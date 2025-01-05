
inherit "/std/pet";

int g_skill = 1;
int g_power = 1;


void setup_golem();

void create() {
    ::create();
    set_name("golem");
    set_id(({ "clay golem", "golem" }));
    set("race", "human");
    set_body_type("human");
    set_attack(1);
    set_carry(0);
    set_save(1);
    set_long("This is a clay golem. He was created by some alchemist. He
doesn't look too strong, but then again, he is made of clay.");
  set_short("clay golem");
set_bodyguard(1);
  set_level(16);
  set_max_hp(260);
  set_hp(260);
  set_property("enhance criticals", ([ "holy" : 1, "impaling" : -1 ]));
  set_skill("melee", 137);
  set_skill("attack", 93);
  set_skill("dodge", 97);
  set_skill("parry", 53);
  set_stats("strength", 105);
  set_property("physical resistance",
               ([ "default" : 20, "iron" : 20, "steel" : 20, "wood" : 20 ]));
  set_aggr_status(0);
  setup_golem();
  return;
}

void set_owner(string who) {
  object ob;

  ob = find_player(who);
  if(!ob) {
    ::set_owner(who);
    return;
  }
  set_languages(({ "undead-tongue", "common", "elvish", "dwarvish",
"serra", "yin", "treefolk",
                 (string)ob->query_primary_lang() }) );
  ::set_owner(who);
  return;
}

void setup_golem(){
    force_me("say ready to serve");
    set_level(14 + g_power + g_skill / 20);
    set_max_hp(220 + g_skill * 5);
    set_hp(220 + g_skill * 5);
    set_max_mp(g_power * 125);
    set_mp(g_power * 125);
    set_property("enhance criticals", 
        ([ "fire" : -2, "cold" : -2, "impact" : -1,
        "plasma" : -1, "vacuum" : -1, "crushing" : -1]));

    set_skill("melee", 120 + g_skill);
    set_skill("attack", 85 + g_skill);
    set_skill("dodge", 85 + g_skill);
    set_skill("parry", 30 + g_skill);
    set_stats("strength", 105);
    set_property("physical resistance",
               ([ "default" : 20, "iron" : 20, "steel" : 20, "wood" : 20 ]));
    set_aggr_status(0);
}

void set_power(int power){
    g_power = power;
}

void set_create_skill(int skill){
    g_skill = skill;
}



void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "A clay golem crumbles to dust.",
          environment());
  remove();
  return;
}


