inherit "/std/pet";

void create() {
int zlevel;
   ::create();

    zlevel = (5+random(5));

   set_level(zlevel);
   set_overall_ac(zlevel+5);
   set_property("magic resistance", zlevel);
   set_skill("resist stun", zlevel);
   set_melee_damage(([ "plasma" : zlevel, "fire" : zlevel, "electricity" : zlevel ]));

    set_name("elemental");
    set_id(({ "elemental", "elemental dragon", "plasma elemental", "dragon" }));
    set_long("This elemental dragon glows with the energy of plasma");
    set_short("["+zlevel+"]plasma elemental dragon");    

    set("race", "elemental");
    set_body_type("winged-humanoid");
    set_gender("neuter");
   //set_alignment(-100);

  set_attack(1);
  set_can_change_aggr(0);
  set_carry(0);
  set_save(0);
set_property("no save", 1);
  set_aggr_status(0);


    set_stats("strength", 50 + 1*zlevel);
    set_stats("dexterity", 50 + 1*zlevel);
    set_stats("constitution", 50 + 1*zlevel);
    set_stats("wisdom", 50 + 1*zlevel);
    set_stats("intelligence", 50 + 1*zlevel);
    set_stats("charisma", 50 + 1*zlevel);
/*
    set_skill("melee", 50 + 1*zlevel);
    set_skill("attack", 50 + 1*zlevel);
    set_skill("defense", 50 + 1*zlevel);
    set_skill("dodge", 50 + 1*zlevel);
*/   
    //set_skill("reverse stroke", 50 + 1*zlevel);
    //set_skill("martial arts",50 + 1*zlevel);
    //set_skill("perception", 50 + 1*zlevel);
    //set_skill("concentrate", 50 + 1*zlevel);
    //set("concentrate", 1);
    //force_me("use concentrate");

  set_skill("elementalism", 175);
  set_skill("plasma lore", 175);
  set_max_mp(1500);
  set_mp(1500);
  set_property("base mp regen", 25);
  set_spell_level("elemental bolt", 6);
  add_spell("elemental bolt", "$A");
  set_spell_level("lesser elemental strike", 6);
  add_spell("lesser elemental strike", "$A");
  set_spell_level("greater elemental bolt bolt", 4);
  add_spell("greater elemental bolt bolt", "$A");
  //set_spell_level("elemental strike", 3+pow/2);
  set_spell_level("elemental strike", 5);
  add_spell("elemental strike", "$A");
  set_spell_level("elemental storm", 6);
  add_spell("elemental storm", "", 1);
  set_spell_level("greater elemental storm", 4);
  add_spell("greater elemental storm", "", 1);
  set_combat_chance(100);
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

string query_element() { return "plasma"; }

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "%^GREEN%^%^BOLD%^A elemental dragon winks out of existence.",
	  environment());
  remove();
  return;
}

