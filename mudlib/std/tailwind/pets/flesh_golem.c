
inherit "/std/pet";

int g_skill = 1;
int g_power = 1;

void setup_golem();

void create() {
    ::create();
    set_name("golem");
    set_id(({ "flesh golem", "golem" }));
    set("race", "human");
    set_body_type("human");
    set_attack(1);
    set_carry(0);
    set_save(1);
    set_short("flesh golem");
    set_long("This is a flesh golem. He was created by some alchemist. He
doesn't look too strong, but then again, he is made of weak flesh.");
  set_level(24);
set_bodyguard(1);
  set_max_hp(260);
  set_hp(260);
  set_property("enhance criticals", ([ "holy" : 1, "impaling" : -1 ]));
  set_skill("melee", 200);
  set_skill("attack", 160);
  set_skill("dodge", 107);
  set_skill("parry", 130);
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
    set_level(18 + g_power  + g_skill / 30);
    set_max_hp(600 + g_skill * 4 );
    set_hp(600 + g_skill * 4);
    set_max_mp(500 + g_power * 150 );
    set_mp(500 + g_power * 150);
    set_skill("melee", 100 + g_skill * 2);
    set_skill("attack",100 + g_skill * 2);
    set_skill("dodge", 100 + g_skill);
    set_skill("parry", 65 + g_skill);
    set_stats("strength", 105);
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
  message("info", "A flesh golem rot to dust.",
          environment());
  remove();
  return;
}

