inherit "/std/pet";

void add_poisoning(){
    return;
}

void create() {
  string tmp;

  ::create();
  set_name("angel");
  set_id(({ "angel", "seraph", "seraphim" }));
  set("race", "seraphim");
  set_body_type("winged_humanoid");
  set_languages(({ "common", "serra", "treefolk", "catfolk", "elvish",
                "dwarvish", "stormspeak", "drow" }) );
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(15);
  set_short("Obedient Angel");
  set_gender("male");
  set_long(
    "This small obedient angel stands only a few feet tall.  "
    "His righteousness and inner light shine brightly but provide no light at all.  "
    "Despite his small size, you sense holy powers protecting him.  ");
  set_overall_ac(15);
  set_casting_chance(4);
  set_combat_chance(80);
  set_aggr_status(0);
  set_can_change_aggr(1);
  return;
}

void set_up(int pow) {
  set_level(20 + pow/2);
  set_max_hp(query_max_hp() * (pow / 3 + 1));
  set_hp(query_max_hp());
  set_property("base hp regen", 30 * pow);
  set_stats("constitution", 50 + 20*pow);
  set_stats("wisdom", 50 + 20*pow);
  set_skill("perception", 200 + 200*pow);
  set_property("melee damage", ([ "crushing" : (10 + 5*pow),
                               "holy" : (45 + 20*pow) ]) );
  return;
}
