/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("polkin buds");
  set("id", ({"buds", "polkin buds"}) );
  set("short", "a few polkin buds");
  set("long", "These small buds are from a squatty flower called a "
              "polkin.  Polkins grow in small clumps under the leaves "
              "of larger plants, usually.");
  set_weight(3+random(3));
  set_toxin_level(65+random(4));
  set_strength(2);
  crit_type = "blindness";
  crit_level = "C";
}
