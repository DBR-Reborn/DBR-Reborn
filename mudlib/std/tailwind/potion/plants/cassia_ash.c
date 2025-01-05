inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("cassia ash");
  set("id", ({"cassia ash", "ash", "pollen"}) );
  set("short", "a handful of cassia ash");
  set("long", "Cassia ash is the bluish pollen taken from the very rare "
              "flower of the Cassian Flight, a species of tropical plants.  The "
              "pollen is very fine and smells bitter.");
  set_weight(3+random(3));
  set_toxin_level(70+random(4));
  set_strength(5+random(4));
  crit_type = "blindness";
  crit_level = "E";

  set_value(300);
}
