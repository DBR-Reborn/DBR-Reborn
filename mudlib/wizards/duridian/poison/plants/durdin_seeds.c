/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("draco thorns");
  set("id", ({"draco thorns", "thorns"}) );
  set("short", "a handful of draco thorns");
  set("long", "These small thorns are from the draco vine, a rare vine "
              "infamous for wrapping itself around the trunks of trees "
              "and choking them to death.");
  set_weight(3+random(5));
  set_toxin_level(92+random(4));
  set_strength(5);
  crit_type = "paralysis";
  crit_level = "E";
}
