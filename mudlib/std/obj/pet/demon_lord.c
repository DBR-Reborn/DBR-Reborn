//    Summon Rune Demon Lord - Xavier Jul2020

inherit "/std/pet";

int power;

void create() {
  ::create();
  set_save(0);
set_property("no save", 1);
  set_attack(1);
  set_carry(0);
  set_can_change_aggr(0);
  set_property("enhance criticals", -4);
  set_name("demon");
  set_aggr_status(1);
  set_overall_ac(125);
  set_id(({ "demon lord", "lord" }));
  set_short("Demon Lord");
  set_body_type("winged-humanoid");
  set("race", "demon");
  set_long(
  "The demon is a huge, red, winged creature with mischeivous eyes.");
  return;
}

set_up(int pow) {
  power = pow;
  set_level(30+pow/2);
  set_max_hp(2500 + 90*pow);
  set_hp(2500 + 90*pow);
  set_skill("melee", 200 + pow * 7);
  set_skill("parry", 175 + pow * 6);
  set_skill("dodge", 175 + pow * 6);
  set_skill("chaos magic", 125);
  set_max_mp(2000 + 90* pow);
  set_mp(2000 + 90*pow);
  set_melee_damage(([ "disruption" : 75 + 7*pow ]));
  set_spell_level("disruption bolt", 6);
  add_spell("disruption bolt", "$A");
  set_spell_level("chaos ball", 6);
  add_spell("chaos ball", "$A");
  set_combat_chance(120);
  return;
}

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
  message("info", "%^GREEN%^%^BOLD%^A demon lord winks out of existence.",
    environment());
  remove();
  return;
}

