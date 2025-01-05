inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("black grass");
  set("id", ({"grass", "black grass"}) );
  set("short", "a handful of black grass");
  set("long", "In your hand is a large handful of black grass, a species "
              "of plant available most everywhere in the plains.  The blades "
              "of grass are wider and somewhat longer than those of the "
              "more common purple variety.");
  set_weight(3+random(3));
  set_toxin_level(9+random(5));
  set_strength(3);
}
