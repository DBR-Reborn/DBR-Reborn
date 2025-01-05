inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("notef buds");
  set("id", ({"buds", "notef buds"}) );
  set("short", "a few notef buds");
  set("long", "These small buds are from a majstic flower called a "
              "notef.  Notefs grow in small clumps under the leaves "
              "of larger plants, usually.");
  set_weight(3+random(3));
  set_toxin_level(65+random(4));
  set_strength(2);
  crit_type = "blindness";
  crit_level = "C";

}
