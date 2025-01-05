inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("blue grass");
  set("id", ({"grass", "blue grass"}) );
  set("short", "a handful of blue grass");
  set("long", "In your hand is a small clump of blue grass, which is the"
              "least common variety of plant in the plains of the land.  It"
              "is the main source of food for many animals.");
  set_weight(3+random(5));
  set_toxin_level(5+random(3));
  set_strength(3);
}
