inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("ktores sprouts");
  set("id", ({"sprouts", "ktores sprouts"}) );
  set("short", "a small handful of ktores sprouts");
  set("long", "The blue and yellow ktores sprouts usually are found on the "
              "edge of the great plain that lies south of Akkad.  The "
              "individual sprouts are very small and very delicate.");
  set_weight(3+random(5));
  set_toxin_level(43+random(4));
  set_strength(5);
}
