
inherit MONSTER;


void create() {
  object ob;

  ::create();

  set("short", "Bob The Healer");
  set("long", @TEXT
I am Bob the Healer and I will cast lesser versions of these spells to assist you in your quest

Just tell me or
"say healer, <txt> me" and I will bless you 
syntax = say healer, boa <your name> 

Here are the spells:
boa Blessing of agility (x2)
bok Blessing of knowledge (x2) 
aof Armour of faith (x6)
dm Divine might (x3)
dt Divine transformation
im increase metabolism (haste)
enlarge

rp Remove poison
sh Satisfy hunger
TEXT
);
  set_level(50);
  set_max_hp(35000);
  set_hp(35000);
  set_max_mp(30000);
  set_mp(30000);
  set_overall_ac(60);
  set_property("base mp regen", 250);
  set_property("base hp regen", 20);
  set_gender("male");
  set("race", "human");
  set_body_type("human");
  set_class("cleric");  
  set_skill("perception", 150);
  set_skill("melee", 2000);
  set_skill("dodge", 1500);
  set_skill("parry", 1500);
  set_skill("blunt", 870);
  set_stats("strength", 79);
  set_stats("wisdom", 140);
  set_skill("attack", 200);
  set_skill("body alteration", 200);
  set_skill("prayer", 200);

  
  //set_spell_level("cure light wounds", 6);
  //add_spell("cure light wounds", "$R");
  set_spell_level("cure serious wounds", 6);
  add_spell("cure serious wounds", "$(ME)");
  set_spell_level("heal", 6);
  add_spell("heal", "$(ME)");

  set_spell_level("blessing of agility", 6);
  add_spell("blessing of agility");
  set_spell_level("blessing of knowledge", 6);
  add_spell("blessing of knowledge");
  set_spell_level("armour of faith", 6);
  add_spell("armour of faith");
  set_spell_level("divine might", 6);
  add_spell("divine might");
  set_spell_level("divine transformation", 6);
  add_spell("divine transformation");
  set_spell_level("increase metabolism", 6);
  add_spell("increase metabolism");

  set_skill("magery", 200);
  set_spell_level("enlarge", 6);
  add_spell("enlarge");


  set_spell_level("remove poison", 6);
  add_spell("remove poison");
  set_spell_level("satisfy hunger", 6);
  add_spell("satisfy hunger");


  //set_casting_chance(10);
  //set_combat_chance(120);
  
  set_id(({ "bob", "healer", "Bob", "Healer", "buff" }));
  
  set_name("healer");
  
  set_property("ambidextry", 1);
  set_property("melee damage", ([ "crushing" : 50000, "holy" : 30000 ]));
  set_languages(({ "common", "serra", "yin", "treefolk", "catfolk",
                   "elvish", "dwarvish", "undead-tongue", "rachk",
                   "gnollish", "stormspeak", }));
  return;
}

int query_num_rounds() { return 2; }


void catch_tell(string str) {
  string who;
  object plyr, *inv;

  str = eliminate_colour(str);
  if(sscanf(str, "%s enters.", who)) {
      plyr = present(lower_case(who), environment());
    if(!plyr) {
      return;
    }
    if(plyr->is_player()) {
    message("info", 
"The Healer begins to cast a spell at "+who, environment(this_object()), this_object());
      force_me("cast *6 heal at "+(string)plyr->query_name());       
    }
    return;
  }
}


void directed_message(object cust, string cmd) {
  string who, what;

  if(sscanf(cmd, "boa %s", what)) {
  who = (string)cust->query_cap_name();
         message("info", 
"The Healer begins to cast a spell at "+who, environment(this_object()), this_object());
    force_me("cast *3 blessing of agility at "+who);
    return;
    }
  if(sscanf(cmd, "bok %s", what)) {
  who = (string)cust->query_cap_name();
         message("info", 
"The Healer begins to cast a spell at "+who, environment(this_object()), this_object());
    force_me("cast *3 blessing of knowledge at "+who);
    return;
    }
  if(sscanf(cmd, "aof %s", what)) {
  who = (string)cust->query_cap_name();
         message("info", 
"The Healer begins to cast a spell at "+who, environment(this_object()), this_object());
    force_me("cast *3 armour of faith at "+who);
    return;
    }
  if(sscanf(cmd, "dm %s", what)) {
  who = (string)cust->query_cap_name();
         message("info", 
"The Healer begins to cast a spell at "+who, environment(this_object()), this_object());
    force_me("cast *3 divine might at "+who);
    return;
    }
  if(sscanf(cmd, "dt %s", what)) {
  who = (string)cust->query_cap_name();
         message("info", 
"The Healer begins to cast a spell at "+who, environment(this_object()), this_object());
    force_me("cast *3 divine transformation at "+who);
    return;
    }
  if(sscanf(cmd, "im %s", what)) {
  who = (string)cust->query_cap_name();
         message("info", 
"The Healer begins to cast a spell at "+who, environment(this_object()), this_object());
    force_me("cast *3 increase metabolism at "+who);
    return;
    }
  if(sscanf(cmd, "enlarge %s", what)) {
  who = (string)cust->query_cap_name();
         message("info", 
"The Healer begins to cast a spell at "+who, environment(this_object()), this_object());
    force_me("cast *3 enlarge at "+who);
    return;
    }


  if(sscanf(cmd, "rp %s", what)) {
  who = (string)cust->query_cap_name();
         message("info", 
"The Healer begins to cast a spell at "+who, environment(this_object()), this_object());
    force_me("cast *6 remove poison at "+who);
    return;
    }
  if(sscanf(cmd, "sh %s", what)) {
  who = (string)cust->query_cap_name();
         message("info", 
"The Healer begins to cast a spell at "+who, environment(this_object()), this_object());
    force_me("cast *2 satisfy hunger at "+who);
    return;
    }

}
