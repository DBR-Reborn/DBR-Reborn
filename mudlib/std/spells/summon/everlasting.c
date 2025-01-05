inherit "/std/pet";

void create() {
  ::create();
  set_name("everlasting");
  set_combat_chance(120);
  set_id(({ "everlasting", "everlasting death", "undead"}));
  set("race", "undead");
  set_body_type("humanoid");
  set_attack(1);
  set_can_change_aggr(1);
  //set_change_ownership(0);
  set_carry(0);
  set_save(1);
  set_property("magic resistance", 120);
  set_skill("resist stun", 375);
  set("see invis", 1);
  set_property("enhance criticals", -5);
  set_level(65);
  set_overall_ac(500);
  //set_overall_ac(100);
  set_short("ghastly being of everlasting death");
  set_long("Your eyes struggle to focus as you appear to see right through the everlasting");
  set_property("physical resistance", ([ "default" : 500]));
  set_property("magical resistance", ([ "default" : 500]));
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
  set_property("power", pow);
  set_max_hp(pow * 3000 );
  set_hp(pow * 3000 );
  set_max_mp(2000 * pow);
  set_mp(2000 * pow);
  set_skill("melee", 250 + 10*pow);
  set_skill("dodge", 80 + 10*pow);
  set_skill("parry", 85 +10*pow);
  set_skill("attack", 250 + 10*pow);
  set_stats("strength", 120 + 10 * pow);
  set_property("melee damage", ([ "cold" : 100 + (10 * pow), "unholy" : 100 + (10 * pow), "infernal" : 100 + (10 * pow), "disruption" : 100 + (10 * pow) ]) );
  set_stats("intelligence", 120);
  set_skill("elementalism", 115+3*pow);
  set_skill("nexus lore", 115+3*pow);
  set_skill("black magic", 150+5*pow);
  set_skill("paralysis magic", 115+3*pow);
  //set_spell_level("wind of death", 6);
  //add_spell("wind of death", "$A");
  set_spell_level("lifesteal", 6);
  add_spell("lifesteal", "$A");
  set_spell_level("decay", 6);
  add_spell("decay", "$A");
  set_spell_level("syphon soul", 6);
  add_spell("syphon soul", "$A");
  add_spell("stun blast", "$A");
  set_spell_level("stun blast", 6);
  add_spell("greater elemental storm", "$A");
  set_spell_level("greater elemental storm", 6);
  add_spell("greater elemental strike", "$A");
  set_spell_level("greater elemental strike", 6);
  set_skill("concentrate", 500);
    force_me("use concentrate");
  return;
}

string query_element() { return "nexus"; }

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void die(object ob) {
   object ob1;
   int power = 12;

   seteuid(getuid());
  ob1 = new("/std/spells/summon/everlasting_2");
  ob1->set_up(power);
  ob1->set_owner(Pet_data["owner"]);
  ob1->set_aggr_status(1);
  ob1->set_dur(300*(1+random(3)));
  ob1->move(environment());
    message("info", "%^GREEN%^%^BOLD%^As the everlasting dies it becomes renewed...and more powerful.",
	  environment());
::die();

   }


