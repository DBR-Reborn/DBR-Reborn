inherit "/std/pet";

void create() {
  ::create();
  set_name("elemental");
  set_id(({ "elemental", "lesser elemental", "air elemental" }));
  set("race", "elemental");
  set_body_type("human");

  set_attack(1);
  set_can_change_aggr(0);
  set_carry(0);
  set_save(0);

  set_level(5);
  set_overall_ac(5);
  set_short("lesser air elemental");
  set_long("This lesser elemental glows with the energy of air");
  set_aggr_status(0);

	set_melee_damage( (["vacuum" : 5 ]) );
    //set_property("enhance criticals",-5);
    //set_property("magic resistance", 25);
    //set_skill("resist stun", 25);
    //set_overall_ac(10);
    
    //set_stats("strength", 120 + random(30));
    //set_stats("dexterity", 120 + random(30));
    //set_stats("constitution", 120 + random(20));
    //set_stats("wisdom", 50 + random(20));
    set_stats("intelligence", 90 + random(20));
    //set_stats("charisma", 80);

    //set_skill("melee", 110);
    //set_skill("attack", 110);
    //set_skill("defense", 110);
    //set_skill("dodge", 110);
    //set_skill("reverse stroke", 110);
    //set_skill("martial arts",110);
    //set_skill("perception", 110);
    //set_skill("concentrate", 110);
    //set("concentrate", 1);
    //force_me("use concentrate");

  set_skill("elementalism", 75);
  set_skill("air lore", 75);
  set_max_mp(250);
  set_mp(250);
  set_spell_level("lesser elemental bolt", 2);
  add_spell("lesser elemental bolt", "$A");
  set_combat_chance(50);
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

string query_element() { return "air"; }

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "%^GREEN%^%^BOLD%^A lesser elemental winks out of existence.",
	  environment());
  remove();
  return;
}

/*ELEMENTAL LIST

1
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_level())+"]Air Elemental");

2
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_level())+"]Water Elemental");

3
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_level())+"]Earth Elemental");

4
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_level())+"]Fire Elemental");

5
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_level())+"]Cold Elemental");

6
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_level())+"]Wind Elemental");

7
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_level())+"]Ice Elemental");

8
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_level())+"]Electricity Elemental");

9
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_level())+"]Inertia Elemental");

10
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_level())+"]Plasma Elemental");

11
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_level())+"]Vacid Elemental");
*/

