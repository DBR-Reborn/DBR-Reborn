/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("nagasik leaves");
  set("id", ({"leaves", "nagasik leaves"}) );
  set("short", "a handful of nagasik leaves");
  set("long", "In the palm of your hand is a few dozen small leaves "
              "from a nagasik bush.  In the summer months the nagasik "
              "bush produces large, sweet-smelling, light pink flowers.");
  set_weight(3+random(2));
  set_toxin_level(40+random(4));
  set_strength(2);
  crit_type = "blindness";
  crit_level = "B";
}
