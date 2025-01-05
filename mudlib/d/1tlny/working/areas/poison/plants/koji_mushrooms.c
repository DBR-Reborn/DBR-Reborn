/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("koji mushrooms");
  set("id", ({"mushrooms", "koji mushrooms"}) );
  set("short", "a handful of koji mushrooms");
  set("long", "In your hand is a dozen or so koji mushrooms, a variety "
              "of small fungus.  The mushrooms are light gray and have "
              "hundreds of tiny black spots on the stem and cap.");
  set_weight(3+random(3));
  set_strength(5+random(6));
  set_toxin_level(35+random(4));
  crit_type = "paralysis";
  crit_level = "B";
}
