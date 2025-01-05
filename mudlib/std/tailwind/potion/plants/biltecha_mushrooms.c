inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("biltecha mushrooms");
  set("id", ({"biltecha mushrooms", "mushrooms"}) );
  set("short", "a bunch of biltecha mushrooms");
  set("long", "These small, gray and white mottled mushrooms grow "
              "in light, dry places, usually under the high branches of "
              "amluf trees.");
  set_weight(3+random(10));
  set_toxin_level(44+random(5));
  set_strength(5+random(3));
  crit_type = "blindness";
  crit_level = "C";
}
