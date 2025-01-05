inherit "/std/pet";

void create() {
  ::create();
  set_name("abomination");
  set_combat_chance(100);
  set_id(({ "abomination", "undead", "unholy abomination" }));
  set("race", "undead");
  set_body_type("winged-humanoid");
  set_attack(1);
  set_can_change_aggr(1);
  set_carry(0);
  set_save(1);
  set_property("enhance criticals", -4);
  set_level(30);
  set_overall_ac(50);
  set_overall_ac(15);
  set_short("Unholy Abomination");
  set_long("This undead thing is perhaps one of the most ugliest things you have ever seen");
  set_property("physical resistance",
	       ([ "default" : 96, "iron" : 96, "steel" : 96, "wood" : 96,
	            "silver" : -20 ]));
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


void set_up(int pow) {
//HONSPRON 2020 - added for create everlasting body
  set_property("power", pow);
  set_max_hp( pow * 80 + 2000 );
  set_hp( pow * 600 + 5*pow );
  set_skill("melee", 160 + 5*pow);
  set_skill("dodge", 70 + 5*pow);
  set_skill("parry", 75 +5*pow);
  set_stats("strength", 100 + 8 * pow);
  set_property("melee damage", ([ "unholy" : 39 + (4 * pow) ]) );
  set_stats("intelligence", 108);
  set_skill("elementalism", 85+3*pow);
  set_skill("chaos lore", 85+3*pow);
  set_skill("black magic", 100+2*pow);
  set_spell_level("chill touch", 6);
  add_spell("chill touch", "$A");
  set_spell_level("cold blast", 6);
  add_spell("cold blast", "$A");
  set_max_mp(4000);
  set_mp(1000+70*pow);
  set_spell_level("lifesteal", 6);
  add_spell("lifesteal", "$A");
  set_spell_level("decay", 6);
  add_spell("decay", "$A");
  add_spell("greater elemental bolt", "$A");
  set_spell_level("greater elemental bolt", 6);
  add_spell("elemental storm", "$A");
  set_spell_level("elemental storm", 6);
  add_spell("elemental strike", "$A");
  set_spell_level("elemental strike", 6);
  set_skill("concentrate", 200);
    force_me("use concentrate");
  return;
}

string query_element() { return "chaos"; }

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "%^GREEN%^%^BOLD%^A Abomination winks out of existence.",
	  environment());
  remove();
  return;
}

