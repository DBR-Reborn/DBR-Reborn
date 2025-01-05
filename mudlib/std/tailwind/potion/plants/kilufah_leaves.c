inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("kilufah leaves");
  set("id", ({"leaves", "kilufah leaves"}) );
  set("short", "a few kilufah leaves");
  set("long", "These leaves are from the fruit-bearing almfu tree.  Each "
              "light green leaf is about the size of a high-man's hand.");
  set_weight(3+random(10));
  set_toxin_level(30+random(2));
  set_strength(3);
  crit_type = "paralysis";
  crit_level = "A";
}
