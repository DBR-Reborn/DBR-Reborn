inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("nymph kisses");
  set("id", ({"kisses", "nymph kisses"}) );
  set("short", "a pair of nymph winks");
  set("long", "Nymph Kisses are tiny, pink flowers, so named for the pink"
              "lips of a seductive nymph.  They are very "
              "difficult to come by and are the favorite flower of "
              "faeries, pixies, and other playful races.");
  set_weight(3+random(2));
  set_toxin_level(55+random(5));
  set_strength(3);
  crit_type = "paralysis";
  crit_level = "C";
}
