//    A DEMON KING.

inherit "/std/pet";

int power;

void create() {
  ::create();
  set_save(0);
set_property("no save", 1);
  set_attack(1);
  set_carry(0);
  set_can_change_aggr(0);
  set_combat_chance(120);
  set_level(40);
  set_melee_damage( (["crushing" : 140 ]) );
    set_property("enhance criticals",-5);
    set_property("magic resistance", 120);
    set_skill("resist stun", 175);
    set_overall_ac(100);
    set("see invis", 1);
  set_property("physical resistance",
	       ([ "default" : 110, "iron" : 95, "steel" : 95, "wood" : 95 ]));
  set_name("demon");
  set_id(({ "demon king", "king" }));
  set_short("Demon King");
  set_body_type("winged-humanoid");
  set("race", "demon");
  set_long(
  "The demon is a huge, red, winged creature with crazy eyes. ");
  return;
}

set_up(int pow) {
  power = pow;
  set_skill("concentrate", 150);
  set("concentrate", 1);
  force_me("use concentrate");
  set_max_hp(2700 + 90*pow);
  set_hp(2700 + 90*pow);
  set_skill("melee", 150 + pow * 7);
  set_skill("parry", 100 + pow * 6);
  set_skill("dodge", 100 + pow * 6);
  set_skill("chaos magic", 150);
  set_skill("elementalism", 100);
   set_skill("chaos lore", 100);
  set_max_mp(2300 + 90* pow);
  set_mp(2300 + 90*pow);
  set_melee_damage(([ "disruption" : 150 + 7*pow ]));
  set_spell_level("disruption bolt", 6);
  add_spell("disruption bolt", "$A");
  set_spell_level("chaos ball", 6);
  add_spell("chaos ball", "$A");
  set_spell_level("chaos storm", 6);
  add_spell("chaos storm", "$A");
  add_spell("greater elemental bolt", "$A");
  set_spell_level("greater elemental bolt", 6);
  add_spell("elemental storm", "$A");
  set_spell_level("elemental storm", 6);
  add_spell("elemental strike", "$A");
  set_spell_level("elemental strike", 6);
  set_stats("strength", 115);
  set_stats("intelligence", 115);
  return;
}

string query_element() { return "chaos"; }

int query_power() { return power; }

void stabilize() {
  remove_call_out("expire");
  set_save(1);
  set_can_change_aggr(1);
  return;
}

void set_dur(int dur) {
  call_out("expire", dur);
  return;
}

void expire() {
  message("info", "%^GREEN%^%^BOLD%^A demon king winks out of existence.",
    environment());
  remove();
  return;
}

