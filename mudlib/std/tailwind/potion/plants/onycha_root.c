inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("onycha root");
  set("id", ({"onycha root", "root"}) );
  set("short", "a few onycha roots");
  set("long", "The onycha root is a green plant which is hard to find. A"
              "black flower protrudes from the tough skin of the plant. "
              "A few large, pointed, black leaves hang at the top of the roots.");
  set_weight(3+random(5));
  set_toxin_level(60+random(4));
  set_strength(5+random(4));
  crit_type = "paralysis";
  crit_level = "E";
  set_value(200);
}
