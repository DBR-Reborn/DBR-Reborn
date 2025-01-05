/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("yellow grass");
  set("id", ({"grass", "yellow grass"}) );
  set("short", "a handful of yellow grass");
  set("long", "In your hand is a small handful of yellow grass, a species "
              "of plant available most everywhere in the plains.  The
blades "
              "of grass are thinner and somewhat shorter than those of the
"
              "more common purple variety.");
  set_weight(3+random(3));
  set_toxin_level(9+random(5));
  set_strength(3);
}
