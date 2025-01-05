inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("pine combs");
  set("id", ({"pine combs", "combs"}) );
  set("short", "a handful of pine combs");
  set("long", "This is a small handful of pine combs that fell off "
              "one of the pine trees in the main forest of the land.");
  set_weight(3+random(5));
  set_toxin_level(20+random(3));
  set_strength(1);
}
