//    A DEMON PRINCE.

inherit "/std/pet";

int power;

void create() {
  ::create();
  set_save(1);
  set_attack(1);
  set_carry(0);
  set_can_change_aggr(1);
  set_aggr_status(0);
  set_combat_chance(120);
  set_level(40);
    set_property("enhance criticals",-4);
    set_property("magic resistance", 120);
    set_skill("resist stun", 175);
    set_overall_ac(100);
    //set_overall_ac(30);
    set("see invis", 1);
  set_property("physical resistance",
	      ([ "default" : 92, "iron" : 92, "steel" : 92, "wood" : 92 ]));
  set_name("demon");
  set_id(({ "demon prince", "prince", "demon" }));
  set_short("Demon Prince");
  set_body_type("winged-humanoid");
  set("race", "demon");
  set_long(
  "A member of Royality among the Infinite Abyss, this Demon Prince is clad in \
writhing black armour that seems to reach out to the living. It's menacing \
glare is only enhanced by a towering 15 foot height, razor sharp teeth \
glittering from it's foul maw, and blood-crested claws. It laughs \
menancingly at the foolish mortal who dares to challenge it. \n");
  return;
}

void set_owner(string who) {
  object ob;

  ob = find_player(who);
  if(!ob) {
    ::set_owner(who);
    return;
  }
  set_languages(({ "common", "elvish", "dwarvish", "serra", "yin", "treefolk",
		 (string)ob->query_primary_lang() }) );
  ::set_owner(who);
  return;
}


void set_up(int pow) {
  power = pow;
  set_skill("concentrate", 150);
  set("concentrate", 1);
  force_me("use concentrate");
  set_max_hp(2700 + 90*pow);
  set_hp(2700 + 90*pow);
  set_skill("melee", 40 + pow * 10);
  set_skill("parry", 100 + pow * 6);
  set_skill("dodge", 100 + pow * 6);
  set_skill("chaos magic", 150);
  set_skill("black magic", 150);
  set_skill("elementalism", 100);
   set_skill("chaos lore", 100);
  set_max_mp(3000 + 90* pow);
  set_mp(3000 + 90*pow);
  set_property("melee damage", ([ "disruption" : 40 + (10 * pow), "unholy" : 40 + (10 * pow) ]) );
  //set_property("melee damage", ([ "unholy" : 40 + (10 * pow) ]) );
  //set_melee_damage(([ "disruption" : 200 + 10*pow ]));
 // set_melee_damage(([ "unholy" : 200 + 10*pow ]));
  set_spell_level("chaos ball", 6);
  add_spell("chaos ball", "$A");
  set_spell_level("chaos storm", 6);
  add_spell("chaos storm", "$A");
  add_spell("elemental storm", "$A");
  set_spell_level("elemental storm", 6);
  add_spell("greater elemental strike", "$A");
  set_spell_level("greater elemental strike", 6);
  add_spell("lifesteal", "$A");
  set_spell_level("lifesteal", 6);
  set_stats("strength", 115);
  set_stats("intelligence", 115);
  return;
}

string query_element() { return "chaos"; }


void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "%^GREEN%^%^BOLD%^A demon prince winks out of existence.",
    environment());
  remove();
  return;
}

