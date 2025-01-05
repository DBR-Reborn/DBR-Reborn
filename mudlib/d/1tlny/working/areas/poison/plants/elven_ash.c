/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("elven ash");
  set("id", ({"elven ash", "ash", "pollen"}) );
  set("short", "a handful of elven ash");
  set("long", "Elven ash is the pinkish pollen taken from the very rare "
              "flower of the elven esper, a species of cactus.  The "
              "pollen is very fine and smells sweet.");
  set_weight(3+random(3));
  set_toxin_level(70+random(4));
  set_strength(5+random(4));
  crit_type = "blindness";
  crit_level = "E";
  set_value(300);
}
