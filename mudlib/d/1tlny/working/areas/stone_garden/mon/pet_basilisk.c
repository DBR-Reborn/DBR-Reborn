inherit "/std/pet";

void create() {
  ::create();
  set_name("basilisk");
  set_id(({ "basilisk" }));
  set("race", "basilisk");
  set_body_type("basilisk");
  set_attack(0);
  set_carry(1);
  set_save(0);
set_property("no save", 1);
  set_level(5);
  set_short("Baby basilisk");
 set_long("This baby basilisk has a harsh black plate like shell. Its claws "+
 "appear quite strong, and even though it is immature, I would be careful. "+
 "Its eyes are a light yellow color however, instead of a fiery red one. I "+
 "wonder why.");
  set_property("physical resistance",
	       ([ "default" : 30, "iron" : 30, "steel" : 30, "wood" : 30 ]));
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
set_languages(({ "common",
		 (string)ob->query_primary_lang() }) );
  ::set_owner(who);
  return;
}

void set_up(int pow) {
  set_max_hp( pow * 50 + 100 );
  set_hp( pow * 50 + 100 );
  set_stats("strength", 50 + 25 * pow);
  set_property("melee damage", ([ "crushing" : (4 * pow) ]) );
  return;
}

void set_dur(int dur) {
  call_out("remove_basilisk", dur);
  return;
}

void remove_basilisk() {
  this_object()->force_me("drop all");
  message("info", "The basilisk runs off after a grasshopper that jumps out from nowehere.",
	  environment());
  remove();
  return;
}

