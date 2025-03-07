inherit "/std/pet";

	int zlevel;

void create() {
  ::create();

zlevel=(1+random(2));

  set_level(zlevel);
  set_name("bear");
   set_id(({ "bear", "grizzly bear" }));
  set("race", "bear");
  set_body_type("quadruped");
  set_attack(1);
  set_carry(0);
  set_save(0);
set_property("no save", 1);
  set_short("["+zlevel+"]grizzly bear");
  set_long("This intelligent looking animal stares right back at you.");
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
  set_max_hp(100+10*zlevel);
  set_hp(100+10*zlevel);
  set_property("melee damage", ([ "cutting" : 10+zlevel*2, "crushing" : 10+zlevel*2  ]) );
  return;
}
