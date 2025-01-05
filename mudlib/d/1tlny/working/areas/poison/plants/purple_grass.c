/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("purple grass");
  set("id", ({"grass", "purple grass"}) );
  set("short", "a handful of purple grass");
  set("long", "In your hand is a small clump of purple grass, which is the
"
              "most common variety of plant in the plains of the land.  It
"
              "is the main source of food for many animals.");
  set_weight(3+random(5));
  set_toxin_level(5+random(3));
  set_strength(3);
}
