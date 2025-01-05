
inherit "/std/pet";

void add_poisoning(){
    return;
}

void create() {
  string tmp;

  ::create();
  set_name("arch-angel");
  set_id(({ "arch-angel", "angel", "seraph", "seraphim" }));
  set("race", "seraphim");
  set_body_type("winged_humanoid");
  set_languages(({ "common", "serra", "treefolk", "catfolk", "elvish",
                "dwarvish", "stormspeak", "drow" }) );
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(15);
  set_short("Magnificent Arch Angel");
  set_gender("female");
  set_long(
    "This beautifull angel graces you with here presence here.  "
    "Her beauty is only surpassed by her aura of commanding magesty.  "
    "You feel the need to grovel in the presence of this magnificent holy creature.  ");
  set_overall_ac(15);
  set_casting_chance(4);
  set_combat_chance(80);
  set_aggr_status(0);
  set_can_change_aggr(1);
  return;
}

void set_up(int pow) {
  set_level(34 + pow);
  set_max_hp(query_max_hp() * (pow / 2 + 1));
  set_hp(query_max_hp());
  set_property("base hp regen", 50 + 20*pow);
  set_stats("constitution", 90 + 20*pow);
  set_stats("wisdom", 90 + 20*pow);
  set_skill("perception", 500 + 300*pow);
  set_property("melee damage", ([ "crushing" : (20 + 8*pow),
                               "holy" : (55 + 30*pow) ]) );
  return;
}
