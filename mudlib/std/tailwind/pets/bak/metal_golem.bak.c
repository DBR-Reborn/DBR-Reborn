inherit "/std/pet";

void create() {
  ::create();
  set_name("golem");
   set_id(({ "metal golem", "golem" }));
  set("race", "human");
  set_body_type("human");
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(30);
  set_short("metal golem");
  set_long("This is a metal golem. He looks like a tough customer.");
  set_max_hp(260);
  set_hp(260);
  set_skill("melee", 250);
  set_skill("attack", 250);
  set_skill("dodge", 140);
  set_skill("parry", 180);
  set_stats("strength", 105);
  set_aggr_status(0);
  return;
}

string query_short() {
  return capitalize(article(query_property("material_name") + " golem"));
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
  message("info", "A metal golem crumbles to dust.",
	  environment());
  remove();
  return;
}