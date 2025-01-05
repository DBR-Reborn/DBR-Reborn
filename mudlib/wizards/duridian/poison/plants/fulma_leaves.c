/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("fulma leaves");
  set("id", ({"leaves", "fulma leaves"}) );
  set("short", "a few fulma leaves");
  set("long", "These leaves are from the fruit-bearing fulma tree.  Each "
              "dark green leaf is about the size of a high-man's hand.");
  set_weight(3+random(10));
  set_toxin_level(30+random(2));
  set_strength(3);
  crit_type = "paralysis";
  crit_level = "A";
}
