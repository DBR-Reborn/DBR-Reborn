/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("pixie winks");
  set("id", ({"winks", "pixie winks"}) );
  set("short", "a couple of pixie winks");
  set("long", "Pixie winks are tiny, white flowers, so named for the white
"
              "aura that sometimes surrounds pixies.  They are very "
              "difficult to come by and are the favorite flower of "
              "faeries, pixies, and other playful races.");
  set_weight(3+random(2));
  set_toxin_level(55+random(5));
  set_strength(3);
  crit_type = "paralysis";
  crit_level = "C";
}
