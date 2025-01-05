/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("pine needles");
  set("id", ({"pine needles", "needles"}) );
  set("short", "a handful of pine needles");
  set("long", "This is a small handful of pine needles that fell off "
              "one of the pine trees in the main forest of the land.");
  set_weight(3+random(5));
  set_toxin_level(20+random(3));
  set_strength(1);
}
