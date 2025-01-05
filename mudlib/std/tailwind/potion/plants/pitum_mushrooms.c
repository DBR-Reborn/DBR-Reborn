inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("pitum mushrooms");
  set("id", ({"mushrooms", "pitum mushrooms"}) );
  set("short", "a handful of pitum mushrooms");
  set("long", "In your hand is a dozen or so pitum mushrooms, a variety "
              "of small fungus.  The mushrooms are light brown and have "
              "dozens of tiny white spots on the stem and cap.");
  set_weight(3+random(3));
  set_strength(5+random(6));
  set_toxin_level(35+random(4));
  crit_type = "paralysis";
  crit_level = "B";

}
