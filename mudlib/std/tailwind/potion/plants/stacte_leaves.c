inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("stacte leaves");
  set("id", ({"stacte leaves", "leaves"}) );
  set("short", "a pile of stacte leaves");
  set("long", "Stacte leaves have long been used in concocting strong "
              "healing potions.  They are large, with a bluish-"
              "green color.");
  set_weight(3+random(5));
  set_toxin_level(90+random(4));
  set_strength(5+random(4));
  crit_type = "paralysis";
  crit_level = "D";
}
