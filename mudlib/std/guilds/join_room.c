//    A generic inheritable object fro guild joining rooms.  Note that 
//    the player must have permission from the guildmaster to join.
//    NPC guildmasters will give permission to any guildless person.
//    Handles all necessary changes to the character, including
//    setting of class, mods of stats, etc.  The join room also 
//    saves itself so the guildmaster can have access to the total
//    guild membership.
//
//    DarkeLIB 0.1
//    -Diewarzau 8/8/95

#include "/adm/include/std.h"
#include "/adm/include/security.h"

inherit ROOM;

mapping guild_list;
mapping banish;
static string class_name;
string master;
static private string *related_guilds;
static private string guild_obj;
static private string *hated_guilds;
static private string *odd_guilds;
static private string *no_guilds;
static private string *other_guilds;

private void save_this_room();
string query_class_name();
string *query_all_members();
void set_guild_obj(string file);
string *query_member_privs(string plyr);
int clean_members();
void kick_member(string member);

int alphabetize(string first, string next) {
	return strcmp(explode(first," ")[0],explode(next," ")[0]);
}

void set_related_guilds(string *guilds) {
  related_guilds = guilds;
  return;
}
//add
void set_hated_guilds(string *guilds) {
  hated_guilds = guilds;
  return;
}

void set_odd_guilds(string *guilds) {
  odd_guilds = guilds;
  return;
}

void set_no_guilds(string *guilds) {
  no_guilds = guilds;
  return;
}

void set_other_guilds(string *guilds) {
  other_guilds = guilds;
  return;
}
//end

void set_guild_obj(string file) {
  guild_obj = file;
  return;
}

string *query_related_guilds() {
  if(!related_guilds || !pointerp(related_guilds)) return ({ });
  return related_guilds;
}

//add
string *query_hated_guilds() {
  if(!hated_guilds || !pointerp(hated_guilds)) return ({ });
  return hated_guilds;
}

string *query_odd_guilds() {
  if(!odd_guilds || !pointerp(odd_guilds)) return ({ });
  return odd_guilds;
}

string *query_no_guilds() {
  if(!no_guilds || !pointerp(no_guilds)) return ({ });
  return no_guilds;
}

string *query_other_guilds() {
  if(!other_guilds || !pointerp(other_guilds)) return ({ });
  return other_guilds;
}
//end

void create() {
  string which;

  ::create();
  which = (string)this_object()->query_class_name();
  banish = ([]);
  guild_list = ([]);
  master = 0;
  seteuid(UID_DAMNED_DATA);
  if(file_exists("/d/damned/data/guild_"+which+".o"))
    restore_object("/d/damned/data/guild_"+which, 1);
  seteuid(getuid());
  return;
}

void reset() {
  object ob;
  string gm;
  
  if(!(gm = (string)query("guildmaster"))) return;
  if(master) return;
  if(present("guildmaster", this_object())) return;
  seteuid(getuid());
  ob = new(gm);
  ob->move(this_object());
  return;
}

int clean_members() {
  string which, *m_list;
  int x,y;

  which = (string)this_object()->query_class_name();
  m_list = query_all_members();
  y = 0;
  for(x=0;x<sizeof(m_list);x++) {
    if(!user_exists(m_list[x])) {
      "/daemon/chat"->send_chat(which,"Scribe","Clean Member:  "+
        capitalize(m_list[x]));
      kick_member(m_list[x]);
      y++;
    }
    if( (int)verify_dir_exists("/wizards/"+m_list[x]) == 1) {
      "/daemon/chat"->send_chat(which,"Scribe","Clean Member:  "+
        capitalize(m_list[x])+" %^RED%^IMMORTAL PURGED%^RESET%^");
      kick_member(m_list[x]);
      y++;
    }

  }
  "/daemon/chat"->send_chat(which,"Scribe","%^RED%^%^BOLD%^Clean Summary%^RESET%^:  "+
    "Origional "+sizeof(m_list)+" Cleaned "+y+" Remaining Members "+(sizeof(m_list)-y));
  return y;
}
void set(string what, mixed val) {
  string *allowers, *council, tmp_str, tmp_str2;
  int i, x;

  if(what == "long" || what == "day long" || what == "night long") {
    val += "\nYou may join by typing '%^CYAN%^join%^RESET%^'.\n"+
           "To cross train, type '%^CYAN%^dual%^RESET%^'.";
    if(master) {
      val += "  The guildmaster is %^CYAN%^"+capitalize(master)+"%^RESET%^.";
      council = filter_array(query_all_members(), "filter_council", this_object());
      council += ({ master });
      x = sizeof(council);
      if(x) {
        tmp_str2 = "%^RESET%^\nThe following players are guild councillors:\n%^CYAN%^";
        while(x--) {
          tmp_str2 += " "+council[x];
          if(x == 0) tmp_str2 += ".";
          else tmp_str2 += ",";
        }
      }
      allowers = filter_array(query_all_members(), "filter_allow_join",
	  this_object());
      i = sizeof(allowers);
      if(i) {
        tmp_str = "%^RESET%^\nThe following players may also allow you to join:\n%^CYAN%^";
	while(i--) {
	  tmp_str += " "+allowers[i];
	  if(i == 0) tmp_str += "%^RESET%^.";
	  else tmp_str += ",";
	}
      }
if(tmp_str2)
      val += tmp_str2;
if(tmp_str)
      val += tmp_str;
    }
  }
  ::set(what, val);
  return;
}

void set_class_name(string str) {
  class_name = str;
}

string query_class_name() {
  return class_name;
}

void init() {
  ::init();
    add_action("join_func", "join");
    add_action("allow_player", "allow");
    add_action("list_members", "list");
	add_action("second_train","dual");
    return;
}

private void save_this_room() {
  seteuid(UID_DAMNED_DATA);
  save_object("/d/damned/data/guild_"+(string)this_object()->query_class_name());
  seteuid(getuid());
  return;
}

string *query_all_members() {
  if(!guild_list || !mapp(guild_list)) return ({ });
  else return filter_array(keys(guild_list), "allow_train_filter", this_object());
}

// list members moved down ++Drizzt 7/10/96

int is_member(string who) {
  return (member_array(who, query_all_members()) >= 0);
}

string query_member_status(string member) {
  if(!guild_list || !mapp(guild_list) || !guild_list[member])
    return 0;
  else if(undefinedp(guild_list[member]["status"])) {
    guild_list[member]["status"] = "not joined";
    return "not joined";
  }
  else return guild_list[member]["status"];
}

string *query_member_privs(string member) {
  if(!guild_list || !mapp(guild_list) || !guild_list[member])
    return ({ });
  else if(undefinedp(guild_list[member]["privs"]) || !pointerp(guild_list[member]
							   ["privs"]))
    return ({ });
  else return guild_list[member]["privs"];
}

int filter_allow_join(string plyr) {
  string *privs;

  privs = query_member_privs(plyr);
  if(!pointerp(privs) || member_array("allow join", privs) < 0)
    return 0;
  return 1;
}

int filter_council(string plyr) {
  string *privs;

  privs = query_member_privs(plyr);
  if(!pointerp(privs) || member_array("council", privs) < 0 || plyr==master) return 0;
  return 1;
}

void set_member_status(string member, string str) {
  if(!guild_list) guild_list = ([]);
  if(!guild_list[member]) guild_list[member] = ([]);
  guild_list[member]["status"] = str;
  save_this_room();
  return;
}

int allow_join(string str) {
  object who;
  string what;

  if(!str) return 0;
  if(!archp(this_player()) && member_array("allow join",
    query_member_privs((string)this_player()->query_name())) < 0)
    return 0;
  who = present(lower_case(str), environment(this_player()));
  if(!who || !who->is_player()) {
    write(capitalize(str)+" isn't here.");
    return 1;
  }
  what = (string)this_object()->query_class_name();
  if(who->query_class() && (string)who->query_class() == what) {
    write(capitalize(str)+" is already a member of this guild.");
    return 1;
  }
  this_object()->set_member_status((string)who->query_name(), "allow join");
  write(capitalize(str) + " may now train here.");
  message("info", "You may now train at the "+class_name+" guild.", who);
  return 1;
}

void add_member_priv(string member, string priv) {
  if(!guild_list) guild_list = ([]);
  if(!guild_list[member]) guild_list[member] = ([]);
  if(!guild_list[member]["privs"]) guild_list[member]["privs"] = ({});
  guild_list[member]["privs"] = distinct_array(guild_list[member]["privs"]
					    + ({ priv }));
  save_this_room();
  return;
}


int list_members() {
  string *wib_mem;
  string foo = "";
  int x;
//  Don't want just anyone to see the list ++Drizzt 7/10/96
  if(!archp(this_player()) && member_array("allow join",
    query_member_privs((string)this_player()->query_name())) < 0)
    return 0;
  wib_mem = query_all_members();
  wib_mem = sort_array(wib_mem,"alphabetize",this_object());
  foo = format_page(wib_mem, 5);
  write("%^GREEN%^+"+sprintf("%|30'-'s", (capitalize(query_class_name()))+" Membership")+
        "-------------------------------------+%^RESET%^\n");
  write(foo);
  write("%^GREEN%^+-------------------------------------------------------------------+"); 
  return 1;
}

void remove_member_priv(string member, string priv) {
  int pos;

  if(!guild_list) guild_list = ([]);
  if(!guild_list[member]) guild_list[member] = ([]);
  if(!guild_list[member]["privs"]) return;
  if((pos = member_array(priv, guild_list[member]["privs"])) < 0)
    return;
  guild_list[member]["privs"] -= ({ guild_list[member]["privs"][pos] });
  save_this_room();
  return;
}

int allow_train_filter(string who) {
  if((string)this_object()->query_member_status(who) == "allow train"
     || (string)this_object()->query_member_status(who) == "not joined") return 0;
  else return 1;
}

void kick_member(string member) {
  object ob;
  mapping mods;
  string *mod_keys;
  int i;

  if(!guild_list) guild_list = ([]);
  if(!guild_list[member]) return;
  map_delete(guild_list, member);
  save_this_room();
  ob = find_player(member);
  if(ob) {
    if((string)ob->query_class() != query_class_name()) return;
    ob->set_class("child");
    message("info", "%^RED%^%^BOLD%^-*> You have been kicked from your guild! <*-", ob);
    mods = (mapping)query_property("guild mods");
    if(mods) {
      mod_keys = keys(mods);
      for(i=0;i<sizeof(mod_keys);i++) {
	if(ob->query_base_stats(mod_keys[i]))
	  ob->set_stats(mod_keys[i], (int)ob->query_base_stats(mod_keys[i]) -
			mods[mod_keys[i]]);
      }
    }
  }
  return;
}
int gm_kick(string str) {
  if(!str) {
    write("You must supply the name of the person you want to banish.");
    return 1;
  }
  if(!is_member(str)) {
    write(str+" is not a member currently.");
    return 1;
  }
  write(@TEXT
You must choose your desired method of banishment:
  1) Time delay--This method will put a 7-day "time bomb" on the player
     and if in the next 7 days the player isn't accepted back as a full
     member s/he will be reincarnated out of the guild with a 15% loss
     of experience.
  2) GM Loss--This method will immediately banish the player; however,
     the player is FREE reinc'd out of the guild and the GM loses 10%
     of hir experience.
  3) Player Agrees--For this method to work, the player must be logged
     on and interactive.  The player will be asked to accept banishment
     and if s/he agrees, the player will be reincarnated out of the
     guild and take a 25% loss of experience.
  4) Abort Banishment--This method will reverse an Option 1 Banish.
TEXT
);
  printf("Which method do you wish to use [1-4]?");
  input_to("gm_kick2",str);
}

void gm_kick2(string str, string who) {
  switch(str) {
    case "1":
      write("Option 1--To be coded.");
      return;
    case "2":
      write("Option 2--To be coded.");
      return;
    case "3":
      write("Option 3--To be coded.");
      return;
    case "4":
      write("Option 4--To be coded.");
      return;
    default:
      printf("Invalid Entry!!!\nWhich method do you wish to use [1-4]?");
      input_to("gm_kick",who);
      return;
  }
}

void add_banish(string who, int when) {
  banish[who] = when;
}
void rm_banish(string who) {
  map_delete(banish, who);
}
mapping query_all_banish() { return banish; }
mapping query_banish(string who) { return banish[who]; }

int join_func() {
  string what, *mod_keys;
  int i;
  mapping mods;

// Added this to remove the requirement for guildmaster permisson
// Thrace (May 5)
  if(this_player()->query_class() && (string)this_player()->query_class()== "child") {
  this_object()->set_member_status(this_player()->query_name(), "not joined");
  }
  what = (string)this_object()->query_class_name();
  if(this_player()->query_class() && (string)this_player()->query_class() !=
     "child" && (string)this_player()->query_class() != what) {
    write("You already belong to another guild.");
    return 1;
  }
// Commented out to remove GM join permission requirement
//  if(!this_object()->query_member_status((string)this_player()->
//                                                        query_name())) {
//    write("You must have the guildmaster's permission to join this guild.");
//    return 1;
//  }
  if((string)this_object()->query_member_status((string)this_player()->
						query_name()) ==
     "allow train") {
    write("You may only train in this guild, not join it.");
    return 1;
  }
  if((string)this_object()->query_member_status((string)this_player()->
						query_name()) !=
     "not joined") {
    write("You are already a member of this guild.");
    return 1;
  }
  write("Welcome to the "+capitalize(what)+" guild!");
  this_player()->set_class(what);
  if(query_property("guild mods") && mapp(query_property("guild mods"))) {
    mod_keys = keys(mods = (mapping)query_property("guild mods"));
    i = sizeof(mod_keys);
    while(i--) {
      if(!this_player()->query_stats(mod_keys[i])) continue;
      this_player()->set_stats(mod_keys[i], (int)this_player()->
			       query_base_stats(mod_keys[i]) + mods[mod_keys[i]]);
    }
  }
  if(query_property("hp advance"))
    this_player()->set_property("hp advance", query_property("hp advance"));
  if(query_property("mp advance"))
    this_player()->set_property("mp advance", query_property("mp advance"));
  if(query_property("base hp regen"))
    this_player()->set_property("base hp regen", query_property("base hp regen"));
  if(query_property("base mp regen"))
    this_player()->set_property("base mp regen", query_property("base mp regen"));
  this_object()->set_member_status(this_player()->query_name(), "member");
  if((int)this_player()->query_level() == 1 &&
	!this_player()->query_property("reincarnate")) {
    this_player()->add_money("gold", 40 + random(30));
    this_player()->add_money("copper", 2500 + 10 * random(150));
    this_player()->add_money("silver", 250 + 2 * random(150));
  }

  return 1;
}

//HONSPRON DUAL TRAIN. Also edited spell_room and skill_room
int second_train() {
  string what;
  string xg1;

  what = (string)this_object()->query_class_name();
  xg1 = (string)this_player()->query_property("cross guild");
  if(this_player()->query_class() && (string)this_player()->query_class() == what) {
    write("You are already a "+capitalize(what));
    return 1;
  }
  if((string)this_object()->query_member_status((string)this_player()->
						query_name()) ==
     "allow train") {
    write("You can already train in this guild.");
    return 1;
  }
  if (this_player()->query_property("cross guild")){ // if we add the skill && this_player()->query_skill("cross training") <= 99) {
    return notify_fail("You already cross train as a "+capitalize(xg1));    
    return 1;
  }
  if (this_player()->query_level() < 1) {
      return notify_fail("You must be level 1 to cross train");
      return 1;
  }
   /* if(this_player()->query_property("cross guild 2")) {
    return notify_fail("You can already train in 2 guilds");    
    return 1; 
  }
    if(this_player()->query_property() != "cross guild 2" && this_player()->query_skill("cross training") >= 100){
    write("You may now train as part of the "+capitalize(what)+" guild!");
    this_player()->set_property("cross guild 2", what);
    this_object()->set_member_status(this_player()->query_name(), "allow train");
    return 1;    
   }*/
  write("You may now train as part of the "+capitalize(what)+" guild!");
  //this_player()->set_skill("cross training", 10);
  this_player()->set_property("cross guild", what);
  this_object()->set_member_status(this_player()->query_name(), "allow train");
  return 1;
}
//END

int set_master(string str) {
  object who, ob;

  str = lower_case(str);
  if(master == str) return 0;
  who = find_player(str);
  if(!who) return 0;
  if(wizardp(who) || (string)who->query_class() != class_name) return 0;
  if(master) {
    message("info", "There is already a player guildmaster of the "+
      class_name+" guild.  Use the 'challenge' command to attempt to "+
      "take the position when he/she is on.", who);
    return 0;
  }
  while(ob = find_object(query("guildmaster"))) ob->remove();
  while(ob = find_object(guild_obj)) ob->remove();
  master = str;
  seteuid(getuid());
  message("info", "%^BLUE%^%^BOLD%^You are now the "+
	  capitalize(class_name) + " Guildmaster!\nType 'help guildmaster'.", 
	  who);
  message("shout", "The Demiurge shouts: All hail "+
	  (string)who->query_cap_name() + ", new guildmaster of the "+
	  capitalize(pluralize(class_name)) + "!", users());
  save_this_room();
  who->save_player((string)who->query_name());
  return 1;
}

void reset_master() {
 /*int i;
  string *m_keys;

  if(guild_list) {
    m_keys = keys(guild_list);
    i = sizeof(m_keys);
    while(i--) if(!mapp(guild_list[m_keys[i]]) || guild_list[m_keys[i]]["status"] != "member")
		  map_delete(guild_list, m_keys[i]);
  }*/
  master = 0;
  save_this_room();
  this_object()->reset();
}

string query_master() { return master; }
