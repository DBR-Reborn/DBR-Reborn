//    Inheritable code for "pets."  Used for monsters which help players
//    out and may be commanded by them.
//
//    DarkeLIB 0.1
//    -Diewarzau 11/9/95
//
//    Revised heavily by glen

#include <daemons.h>
#include <move.h>
#include <std.h>
#include <rooms.h>
#include <dirs.h>

inherit MONSTER;
inherit "/std/locker_logic";

private string my_file;
string block_exit;
mapping Pet_data;
static mapping blocked;
static int saved_here = 1;

string *query_non_aggr();           // query safe people
void add_non_aggr(string who);      // add safer person
void delete_non_aggr(string who);   // remove from safe list
void set_save(int stat);            // saveable
void set_attack(int stat);          // can command to attack
void set_carry(int stat);           // can command to carry
void set_aggr_status(int stat);     // set aggro
void set_owner(string who);         // set the owner
void set_bodyguard(int stat);       // does this pet protect you
void set_bodyblocking(int stat);       // is this pet actually body blocking
void set_change_ownership(int stat);// can change ownership
void set_intelligent(int stat);     // can cast and etc like intelligent being
void set_learning_spells(int stat); // can learns spells
int query_aggr_status(object who);
void set_can_change_aggr(int stat);
string query_cap_name();

string query_storage_key(){return "pet";}
// start glen pet learning code
int get_spell_level_exp(int level){
    switch(level){
    case 1: return 6;
    case 2: return 16;
    case 3: return 31;
    case 4: return 51;
    case 5: return 81;
    case 6: return 100;
    }
    return 0;
}
void set_learned_spells(){
    mapping spexp;
    string *keys;
    int i = 0;

    if(!Pet_data)Pet_data = ([]);

    if(!Pet_data["spell learning"])
	return;

    spexp = query_property("spells experience");
    if(!spexp)
	return;

    keys = keys(spexp);

    for(i = 0; i < sizeof(keys); i++){
	if(query_spell_level(keys[i]) >=
	  query_spell_level(spexp[keys[i]]))
	    continue;

	set_spell_level(keys[i], 
	  get_spell_level_exp(spexp[keys[i]]));
    }
}


void pet_learning_startup(){
    mapping spexp;
    if(!Pet_data)
	Pet_data = ([]);

    if(!Pet_data["spell learning"])
	return;

    spexp = query_property("spells experience");

    if(!spexp)
	spexp = ([]);

    set_property("spells experience", spexp);
}


void spell_cast(string name, string skill, object caster){
    mapping spexp;
    int last_learned;
    if(query_skill(skill) < 1)
	return;

    last_learned = query_property("last spell learned");

    if(time() - last_learned < 45)
	return;
    set_property("last spell learned", time());

    spexp = query_property("spells experience");
    if(!spexp){
	pet_learning_startup();
	return;
    }


    if(spexp[name])
	spexp[name]++;
    else
	spexp[name] = 1;

    set_property("spells experience", spexp);
    set_learned_spells();
}
// end glen pet learning code

string query_cap_name() {
    if(!Pet_data)Pet_data = ([]);
    if(!Pet_data["real name"]) return ::query_cap_name();
    else return capitalize(Pet_data["real name"]);
}

int save_me(string file) {
    saved_here = 1;
    return ::save_me(file);
}

string query_owner() { 
    if(!Pet_data)Pet_data = ([]);
    return Pet_data["owner"]; 
}

string query_short() {
    if(!Pet_data)Pet_data = ([]);
    if(!Pet_data["name"]) return capitalize(::query_short());
    /* changed to the above line by ophelia
	if(!Pet_data["name"]) return capitalize(article(::query_short()));
    */
    return capitalize(Pet_data["name"] + " the " + ::query_short());
}

int is_pet() { return 1; }

void add_exp(int amt) {
    object who;
    int i, lev;
    object *inv;
    string master;
    int masterlevel,totallevel;

    master=this_object()->query_owner();
    who=find_player(master);
    if(!who) return;
    if(environment(this_object()) != environment(who)){
	return;
    }
    masterlevel = (int)who->query_level();
    totallevel = (int)this_object()->query_level();
    totallevel += masterlevel;
    /*
	inv = all_inventory(environment());
	i = sizeof(inv);
	while(i--) {
	    if(inv[i] == this_object()) continue;
	    if(inv[i]->is_pet() && (string)inv[i]->query_owner() ==
	      (string)this_object()->query_owner()){
		totallevel += (int)inv[i]->query_level();
	    }
	}
    */
    amt = to_int(to_float(amt) *
      (to_float(masterlevel)/to_float(totallevel)));
    who->add_exp2(amt);

    return;
}

void create() {
    ::create();
    Pet_data = ([]);
    blocked = ([]);
    Pet_data["attack"] = 1;
    this_object()->set_lang_prof("common", 10);
    set("aggressive", (: call_other, this_object(), "query_aggr_status" :));
    set_storage_key("pet");
    set_skill("swimming", 100);
    set_bodyguard(0);
    set_change_ownership(1);
    call_out("pet_learning_startup", 2);
    return;
}

int receive_objects() {
    if(previous_object() && living(previous_object())) return 0;
    return ::receive_objects();
}

void set_can_change_aggr(int stat) {
    Pet_data["change aggr"] = stat;
    return;
}

void add_non_aggr(string who) {
    if(!Pet_data["non aggr"] ||
      !pointerp(Pet_data["non aggr"])) Pet_data["non aggr"] = ({});
    Pet_data["non aggr"] = distinct_array(Pet_data["non aggr"] + ({ who })
    );
    return;
}

void delete_non_aggr(string who) {
    if(!Pet_data["non aggr"] ||
      !pointerp(Pet_data["non aggr"])) return;
    if(member_array(who, Pet_data["non aggr"]) < 0) return;
    Pet_data["non aggr"] -= ({ who });
    return;
}

string *query_non_aggr() {
    if(!Pet_data["non aggr"] ||
      !pointerp(Pet_data["non aggr"])) return ({});
    return Pet_data["non aggr"];
}

void set_aggr_status(int stat) {
    Pet_data["aggr status"] = stat;
    return;
}

int query_aggr_status(object who) { 
    if(!living(who)) return 0;
    if(wizardp(who)) return 0;
    if(!Pet_data["aggr status"]) return 0;
    if(who->is_pet() && query_owner() == (string)who->query_owner()) 
	return 0;
    if(!who->is_player()) return 1;
    if((string)who->query_name() == query_owner()) return 0;
    if(!Pet_data["non aggr"] || !pointerp(Pet_data["non aggr"])) return 1;
    if(member_array((string)who->query_name(), Pet_data["non aggr"]) >= 0)
	return 0;
    if(who->is_pet() && member_array((string)who->query_owner(),
	Pet_data["non aggr"]) >= 0) return 0;
    return 1;
}


void set_save(int stat) {
    if(!Pet_data)Pet_data = ([]);
    Pet_data["save"] = stat;
}

void set_owner(string who) {
    if(!Pet_data)Pet_data = ([]);
    Pet_data["owner"] = who;
}

void set_attack(int stat) {
    if(!Pet_data)Pet_data = ([]);
    Pet_data["attack"] = stat;
}
void set_learning_spells(int stat){
    if(!Pet_data)Pet_data = ([]);
    Pet_data["spell learning"] = stat;
}

void set_bodyguard(int stat){
    if(!Pet_data)Pet_data = ([]);
    Pet_data["bodyguard"] = stat;
    set_bodyblocking(1);
}

void set_bodyblocking(int stat) {
    if(!Pet_data)Pet_data = ([]);
    Pet_data["bodyblock"] = stat;
}

void set_intelligent(int stat){
    if(!Pet_data)Pet_data = ([]);
    Pet_data["intelligent"] = stat;
}

void set_carry(int stat) {
    if(!Pet_data)Pet_data = ([]);
    Pet_data["carry"] = stat;
}
void set_change_ownership(int stat){
    if(!Pet_data)Pet_data = ([]);
    Pet_data["ownership change"] = stat;
}

void restore_stuff(){
    seteuid(geteuid(this_object()));
    if(Pet_data["name"]) set_name(lower_case(Pet_data["name"]));
    return;
}

string query_my_file() {
    if(!Pet_data["save"]) return 0;
    return my_file;
}

void init() {
    ::init();
    if(block_exit) add_action("exit_func", block_exit);
    return;
}

int exit_func(string null) {
    string *b_keys, p_name;
    int a_flag;

    a_flag = 0;

    if(environment() && member_array(block_exit, (string *)environment()->
	query_exits()) < 0) return 0;
    if(query_attackers() && member_array(this_player(), query_attackers())>= 0)
	a_flag = 1;
    b_keys = keys(blocked);
    if((string)this_player()->query_name() == query_owner()) return 0;
    if(member_array((string)this_player()->query_name(),
	query_non_aggr()) >= 0) return 0;
    if(this_player()->is_pet() && (string)this_player()->query_owner() ==
      (string)this_object()->query_owner()) return 0;
    if(!a_flag && this_player()->query_invis() &&!this_object()->query("see invis"))
	return 0;
    else if(this_player()->query_invis() && !this_object()->query("see invis")) {
	if(random(100) > ((int)this_object()->query_skill("perception")/3))
	    return 0;
    }
    if(this_player()->shadow_form() || this_player()->query_ghost()) return 0;
    p_name = (string)this_player()->query_name();
    if((member_array(p_name, b_keys) < 0 ||
	blocked[p_name] < time()) && !a_flag) {
	if(skill_contest((int)this_player()->query_stealth(),
	    (int)this_object()->query_skill("perception"), 1) == 1)
	    return 0;
    }
    blocked[p_name] = time() + 60 * (int)this_object()->query_level();
    write((string)this_object()->query_short() + " bars your way.");
    message("other_action", (string)this_object()->query_short() +
      " bars "+(string)this_player()->query_cap_name()+
      "'s way as "+nominative(this_player()) +
      " tries to go "+query_verb()+".", environment(this_player()),
      ({ this_player() }) );
    return 1;
}

int move(mixed dest) {
    int flag, res;
    object env;

    if(!environment()) {
	return ::move(dest);
    }
    if(environment()->query_is_locker_room()) {
	flag = 1;
	env = environment();
    }
    else flag = 0;
    if((res = ::move(dest)) == MOVE_OK && flag && saved_here) {
	SAVE_ITEMS_D->update_lockers(env);
    }
    if(res == MOVE_OK) saved_here = 0;
    return res;
}

int query_saved_here() { return saved_here; }

int query_is_locker() {
    if(Pet_data["save"]) return 1;
    else return 0;
}

void directed_message(object from, string mesg) {
    string tmp1, name,nom,who;
    object ob;
    string *tmp_p;
    string *spell_p;
    int i;

    if((string)from->query_name() != query_owner()) return;
    if(!Pet_data["name"]) name = (string)this_object()->query_cap_name();
    else name = capitalize(Pet_data["name"]);
    force_me("speak "+(string)from->query_primary_lang());
    if(!this_object()->query_primary_lang())
	force_me("speak common");
    if(parse_command(mesg, environment(), " 'move' / 'go' %s ", tmp1)) {
	if(!environment() || !environment()->query_exits() ||
	  member_array(lower_case(tmp1), (string *)environment()->query_exits()) < 0) {
	    force_me("say There is no such exit.");
	    return;
	}
	this_object()->force_me(lower_case(tmp1));
	return;
    }
    if((query_level() / 3) > from->query_level()){
	force_me("speak common");
	force_me("say Are you talking to me little guy?");
	return;
    }

//TLNY2024 ADD
  if(parse_command(mesg, environment(), " 'equip' / 'take' %s", tmp1)) {
    if(!Pet_data["carry"]) return;
    this_object()->force_me("equip "+tmp1);
    return;
  }
//END
    if(parse_command(mesg, environment(), " 'get' / 'take' %s", tmp1)) {
	if(!Pet_data["carry"]) return;
	this_object()->force_me("get "+tmp1);
	return;
    }
    if(parse_command(mesg, environment(), " 'attack' / 'kill' %s", tmp1)) {
	ob = present(tmp1, environment());
	if(!Pet_data["attack"] || !ob || !living(ob)) return;
	if((string)ob->query_name() == query_owner()) {
	    message("info", (string)this_object()->query_cap_name() +
	      " refuses to attack "+ possessive(this_object()) +
	      " master.", environment());
	    return;
	}
	message("other_action", (string)this_object()->query_cap_name() +
	  " attacks " + (string)ob->query_cap_name() + "!",
	  environment(), ({ ob }) );
	message("other_action", (string)this_object()->query_cap_name() +
	  " attacks you!", ob);
	this_object()->kill_ob(ob, 0);
	return;
    }
    if(sscanf(mesg, "drop %s", tmp1)) {
	if(!Pet_data["carry"]) return;
	this_object()->force_me(mesg);
	return;
    }
    if(sscanf(mesg, "give %*s")) {
	if(!Pet_data["carry"]) return;
	this_object()->force_me(mesg);
	return;
    }
    if(strlen(mesg) >= 4 && mesg[0..3] == "save") {
	if(!Pet_data["save"])
	    return;
	/*if(!environment()->query_is_locker_room()) {
	    this_object()->force_me("say This room will not save monsters.");
	    return;
	}*/
	//SAVE_ITEMS_D->update_lockers(environment());
	this_object()->force_me("say Save you from what? Your self?");
	saved_here = 1;
	return;
    }
    if(strlen(mesg) >= 5 && mesg[0..4] == "speak") {
	this_object()->force_me(mesg);
	return;
    }
    if(strlen(mesg) >= 8 && mesg[0..7] == "list non") {
	if(!Pet_data["change aggr"]) return;
	message("info", name + " whispers something to "+
	  (string)from->query_cap_name()+".", environment(),
	  ({ from, this_object() }) );
	if(!Pet_data["non aggr"] || !pointerp(Pet_data["non aggr"])) {
	    message("info", "No players on non-aggressive list.", from);
	    return;
	}
	message("info", "Non-aggressive list for "+name+
	  ":\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"+
	  format_page(query_non_aggr(), 2), from);
	return;
    }
    if(sscanf(mesg, "add player %s", tmp1)) {
	if(!Pet_data["change aggr"]) return;
	tmp1 = lower_case(tmp1);
	add_non_aggr(replace_string(tmp1, " ", ""));
	message("info", "Player "+capitalize(replace_string(tmp1, " ", "")) +
	  " added to non-aggressive list for "+
	  name + ".", from);
	if(environment(from) == environment())
	    this_object()->force_me("say Done.");
	return;
    }
    if(sscanf(mesg, "remove player %s", tmp1)) {
	if(!Pet_data["change aggr"]) return;
	tmp1 = lower_case(tmp1);
	delete_non_aggr(replace_string(tmp1, " ", ""));
	message("info", "Player "+capitalize(replace_string(tmp1, " ", "")) +
	  " removed from non-aggressive list for "+
	  name + ".", from);
	if(environment(from) == environment())
	    this_object()->force_me("say Done.");
	return;
    }
    if(strlen(mesg) >= 11 && mesg[0..10] == "toggle aggr") {
	if(!Pet_data["change aggr"]) return;
	if(Pet_data["aggr status"]) {
	    message("info", name + " set to non-agressive.", from);

	    this_object()->set_aggr_status(0);
	}
	else {
	    this_object()->set_aggr_status(1);
	    message("info", name + " set to agressive.", from);
	}
	if(environment(from) == environment())
	    this_object()->force_me("say Done.");
	return;
    }
    if(sscanf(mesg, "cast %s", tmp1)) {
	if(!Pet_data["intelligent"])
	    return;
	message("info", "You order the pet to: " +
	  mesg, from);
	force_me(mesg);
	return;
    }
    if(sscanf(mesg, "name %s", tmp1)) {
	name = replace_string(tmp1, " ", "");
	if(tmp1 != name) {
	    message("info", "There cannot be any spaces in a proper name.", from);
	    return;
	}
	nom = lower_case(name);
	who = sprintf("%s/%s/%s", DIR_USERS, nom[0..0], nom);
	if( !(file_size(who + ".o") < 0)  ) {
	    message("info","You may not name your pet after a player.\n",from);
	    return;
	}
	tmp_p = this_object()->query_id();
	if(Pet_data["name"]) {
	    while((i = member_array(lower_case(Pet_data["name"]), tmp_p)) >= 0)
		tmp_p = exclude_array(tmp_p, i);
	}
	if(!Pet_data["real name"])
	    Pet_data["real name"] = (string)this_object()->query_name();
	this_object()->set_id(distinct_array(tmp_p + ({ lower_case(name) })));
	Pet_data["name"] = name;
	set_name(lower_case(name));
	message("info", "Name changed to "+name+" for "+
	  query_cap_name() + ".", from);
	if(environment(from) == environment())
	    this_object()->force_me("say Ok.");
	return;
    }
    if(strlen(mesg) >= 4 && mesg[0..3] == "help") {
	tmp1 = "Help for
"+name+":\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    tmp1 += "All commands must be tell'ed say'ed or yell'ed to the
monster.\n"+
        "See 'help communication' for details on talking to NPC's.\n";
    tmp1 +=
"move <direction>     Move in specified direction\n" +
"name <proper-name>   Give the monster a unique proper name.\n"+
"speak <language>     Command the monster to speak a specific language,\n"+
"                     if known.\n"+
"follow               toggles follow on or off.  The monster must be in\n"+
"                     the same room as you to start following.\n"+
"stop hunting         Clears the pet's hunting list.  Similar\n"+
"                     to the player command (see 'help stop').\n";
    if(Pet_data["ownership change"]) tmp1 +=
"set owner <who>      Transfers ownership of the monster.\n";
    if(Pet_data["attack"]) tmp1 +=
"attack <who>         If able, attack the specified person / monster.\n"+
"block exit <exit>    The monster will not allow anyone to exit the\n"+
"                     room by that direction.  Players may still enter\n"+
"                     from that direction, though.  Supplying no\n"+
"                     arguement will turn off the exit blocking.\n"+
"                     NOTE: The room need not have the exit supplied;\n"+
"                     the pet will continue to block AFTER it moves, \n"+
"                     until you tell it to stop.\n";

    if(Pet_data["intelligent"]) tmp1 +=
"cast <what>          Order the pet to cast a spell. \n"+
"                     The syntax is the same as you would use.\n"+
"spells list          Get a list of the pets spells. \n";
    if(Pet_data["bodyguard"]) tmp1 +=
"toggle bodyblock     Toggles pet bodyblocking on and off.\n";
    if(Pet_data["carry"]) tmp1 +=
"give <what> to <who> These commands allow the monster to carry items\n"+
"get <item>           for the owner.  This can be useful for \n"+
"drop <item>          especially heavy items.\n"+
"equip                This creature can also equip their inventory \n";
    if(Pet_data["save"]) tmp1 +=
"save                 Saves the monster.  It will stay past reboots,
but\n"+
"                     this only works in rooms which also save items, \n"+
"                     like inn rooms, etc.\n";
    if(Pet_data["change aggr"]) tmp1 +=
"toggle aggressive    Toggles the monster between aggressive and not.\n"+
"                     Aggressives will attack anyone not on the non-\n"+
"                     aggressive list (see below) on sight.  It will\n"+
"                     not attack the owner ever.\n"+
"list non-aggressive  Lists all players on the non-aggressive list for\n"+
"                     the monster.  The owner is not shown here.\n"+
"add player <who>     Adds <who> to the non-aggressive list.\n"+
"remove player <who>  Removes <who> from the non-aggressive list.\n";
    from->more(explode(tmp1, "\n"));
    if(environment(from) == environment())
      message("info", name + " whispers something to "+
              (string)from->query_cap_name() + ".", environment(),
              ({ from, this_object() }) );
    return;
  }
  if(Pet_data["ownership change"])
   if(sscanf(mesg, "set owner %s", tmp1)) {
    ob = find_player(tmp1);
    if(!ob) {
      message("info", "Could not find '"+tmp1+"'.", from);
      return;
    }
    if(environment() != environment(ob)) {
      message("info", "The new owner must be in the same room.", from);
      return;
    }
    i = 0;
    if(pointerp(from->query_followers())) {
    while(member_array(this_object(), 
        (object *)from->query_followers()) >= 0) {
      from->remove_follower(this_object());
      i = 1;
    }
    }
    if(i)
      message("info", (string)this_object()->query_cap_name()+
        " stops following you.", from);
    if((query_level() / 2) - 4 > ob->query_level()){
       force_me("speak common");
       force_me("say I dont work for little chimps like that");
       return;
    }
    set_owner((string)ob->query_name());
    message("info", "You have transferred ownership of "+name+" to "+
            (string)ob->query_cap_name() + ".", from);
    message("info", "Ownership of "+name+" has been transferred to you.", ob);
    this_object()->set_lang_prof((string)ob->query_primary_lang(), 10);
    return;
  }
  if(mesg == "spells list") {
      spell_p = query_all_spells();
      if(!spell_p || sizeof(spell_p) < 1)
          force_me("say I know no spells.");
      for(i = 0; i < sizeof(spell_p); i++)
          force_me("say *" +
          query_spell_level(spell_p[i])
          + " - " + spell_p[i]);
      return;
  }
  if(mesg == "stop hunting") {
    this_object()->stop_hunting();
    force_me("say Okay.");
    return;
  }
if(Pet_data["bodyguard"] && mesg == "toggle bodyblock") {
    if(Pet_data["bodyblock"] == 1) {
        set_bodyblocking(0);
        force_me("say I am no longer defending you Master.");
        return;
    }
    if(Pet_data["bodyblock"] == 0) {
        set_bodyblocking(1);
        force_me("say I am defending you with my life Master.");
        return;
    }
}
  if(mesg == "block exit") {
    block_exit = 0;
    ob = environment();
    if(ob) {
      this_object()->move(ROOM_VOID);
      this_object()->move(ob);
    }
    force_me("say Okay.");
    return;
  }
  if(sscanf(mesg, "block exit %s", tmp1)) {
    if(!Pet_data["attack"]) return;
    if(member_array(tmp1, (string *)environment()->query_exits()) < 0)
      message("info", "Warning, there is no exit with the name '"+tmp1+"'.", from);
    if(environment(this_object())->query_property("no attack")){
        message("info", "I can't block the exit "+tmp1+" in a no-attack room, sorry.", from);
        return;
      }
    block_exit = tmp1;
    ob = environment();
    if(ob) {
      this_object()->move(ROOM_VOID);
      this_object()->move(ob);
    }
    force_me("say Now blocking exit: "+tmp1);
    return;
  }
  if(strlen(mesg) >= 6 && mesg[0..5] == "follow") {
    if((object *)from->query_followers())
      i = member_array(this_object(), (object *)from->query_followers());
    else i = -1;
    if(i < 0) {
      if(environment() != environment(from)) {
        message("info", "You must be in the same room if you want "+name+
                " to follow you.", from);
        return;
      }
      from->add_follower(this_object());
      message("info", name + " starts following you.", from);
      return;
    }
    else {
      message("info", name + " stops following you.", from);
      from->remove_follower(this_object());
      return;
    }
  }
  return;
}

int attack_filter(object who, object own) {
  object *att;
  
  if(!own || !who) return 0;
  if(!living(who)) return 0;
  att = (object *)who->query_attackers();
  if(!att || !sizeof(att)) return 0;
  if(member_array(own, att) < 0) return 0;
  return 1;
}



varargs void heart_beat(int flag) {
  object own, *inv;
  int i;
  
  if(Pet_data["bodyguard"] && Pet_data["bodyblock"]){
    if(query_owner() && (own=present(query_owner(), environment()))) {
      inv = filter_array(all_inventory(environment()), "attack_filter",
          this_object(), own);
      i = sizeof(inv);
      while(i--) {
        if(own && own == (object)inv[i]->query_current_attacker()) {
          message("info", query_short() +" prevents "+
            (string)inv[i]->query_cap_name() +
            " from attcking you!", own);

          message("info", query_short()+" prevents "+
            (string)inv[i]->query_cap_name() +
            " from attcking "+
            (string)own->query_cap_name()+".", environment(),
            ({ own, inv[i] }));

          message("info", query_short() +" prevents you from attacking"+
            (string)own->query_cap_name()+".", inv[i]);
        }
        inv[i]->kill_ob(this_object(), 1);
      }
    }
  }
  ::heart_beat(flag);
}


