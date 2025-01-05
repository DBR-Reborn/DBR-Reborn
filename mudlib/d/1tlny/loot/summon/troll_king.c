inherit "/std/pet";

	int zlevel;

void create() {
  ::create();

zlevel=(50+random(10));

  set_level(zlevel);
  set_name("Troll King");
   set_id(({ "troll king", "troll", "king" }));
  set("race", "human");
  set_body_type("human");
  set_attack(1);
  set_carry(1);
  set_save(0);
  set_short("["+zlevel+"]Troll King");
  set_long("This is the embodyment of the Troll King Himself.");
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
  set_languages(({ "common", "elvish", "serra", "treefolk",
		 (string)ob->query_primary_lang() }) );
  ::set_owner(who);
  return;
}

void set_up() {

    set_skill("martial arts", 50+zlevel*3);
  //set_max_hp(100+10*zlevel);
  //set_hp(100+10*zlevel);
  set_property("melee damage", ([ "cutting" : 50+zlevel*2, "crushing" : 50+zlevel*2, "impact": 50+zlevel*2  ]) );
  return;
}
