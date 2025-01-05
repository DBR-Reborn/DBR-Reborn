inherit "/std/pet";

void create() {
  ::create();
  set_name("golem");
   set_id(({ "iron cobra", "cobra" }));
  set("race", "snake");
  set_body_type("serpent");
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(3);
  set_short("iron cobra");
  set_long("This is an iron cobra. He was created by some alchemist. He looks pretty mean.");
  set_property("physical resistance",
	       ([ "default" : 20, "iron" : 20, "steel" : 20, "wood" : 20 ]));
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
  message("info", "An iron cobra rusts to dust.",
	  environment());
  remove();
  return;
}