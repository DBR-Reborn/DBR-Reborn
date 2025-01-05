
inherit "/std/pet";

int g_skill = 1;
int g_power = 1;

void   setup_golem();

void create() {
    ::create();
    set_name("golem");
    set_id(({ "wood golem", "golem" }));
    set("race", "human");
    set_body_type("human");
    set_attack(1);
    set_carry(0);
    set_save(1);
    set_short("wood golem");
    set_long("This is a wood golem. He was created by some alchemist. He
doesn't look too weak, but since he is made of wood, he is flammable.");
  set_level(10);
set_bodyguard(1);
  set_max_hp(260);
  set_hp(260);
  set_property("enhance criticals", ([ "holy" : 1, "impaling" : -1 ]));
  set_skill("melee", 100);
  set_skill("attack", 70);
  set_skill("dodge", 50);
  set_skill("parry", 75);
  set_stats("strength", 105);
  set_property("physical resistance",
               ([ "default" : 20, "iron" : 20, "steel" : 20, "wood" : 20,
"mithril" : -20 ]));
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
    set_level(8 + g_power  + g_skill / 30);
    set_max_hp(200 + g_skill * 4 );
    set_hp(200 + g_skill * 4);

    set_max_mp(200 + g_power * 12 );
    set_mp(200 + g_power * 12);

    set_property("enhance criticals", 
        ([ "fire" : 1, "impaling" : -2, "cutting" : -2,
        "impact" : -2, "plasma" : 1]));

    set_skill("melee", 80 + g_skill );
    set_skill("attack",70 + g_skill);
    set_skill("dodge", 25 + g_skill);
    set_skill("parry", 50 + g_skill);
    set_stats("strength", 105);
    set_property("physical resistance",
               ([ "default" : 20, "iron" : 20, "steel" : 20, "wood" : 20,
                    "mithril" : -20 ]));
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
  message("info", "A wood golem crumbles to dust.",
          environment());
  remove();
  return;
}

