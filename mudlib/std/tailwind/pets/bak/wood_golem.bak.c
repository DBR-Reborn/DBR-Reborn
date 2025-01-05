inherit "/std/pet";

void create() {
  ::create();
  set_name("golem");
   set_id(({ "wood golem", "golem" }));
  set("race", "human");
  set_body_type("human");
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(10);
  set_short("wood golem");
  set_long("This is a wood golem. He was created by some alchemist. He doesn't look too weak, but since he is made of wood, he is flammable.");
  set_max_hp(260);
  set_hp(260);
  set_property("enhance criticals", ([ "holy" : 1, "impaling" : -1 ]));
  set_skill("melee", 100);
  set_skill("attack", 70);
  set_skill("dodge", 50);
  set_skill("parry", 75);
  set_stats("strength", 105);
  set_property("physical resistance",
	       ([ "default" : 20, "iron" : 20, "steel" : 20, "wood" : 20, "mithril" : -20 ]));
  set_aggr_status(0);
  return;
}

void set_owner(string who) {
  object ob;

  ob = find_player(who);
  if(!ob) {
    ::set_owner(who);
    return;
  }
  set_languages(({ "undead-tongue", "common", "elvish", "dwarvish", "serra", "yin", "treefolk",
		 (string)ob->query_primary_lang() }) );
  ::set_owner(who);
  return;
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