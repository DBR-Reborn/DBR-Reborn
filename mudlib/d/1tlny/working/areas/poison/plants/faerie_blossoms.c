/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("faerie blossoms");
  set("id", ({"faerie blossoms", "blossoms"}) );
  set("short", "several faerie blossoms");
  set("long", "Faerie blossoms are small, pink flowers that are normally "
              "found in swampy areas, but have been known to grow in less "
              "damp places.");
  set_weight(3+random(5));
  set_toxin_level(29+random(4));
  set_strength(4+random(3));
  crit_type = "blindness";
  crit_level = "A";
}
