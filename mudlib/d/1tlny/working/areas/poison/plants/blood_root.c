/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("blood root");
  set("id", ({"blood root", "root"}) );
  set("short", "a few pieces of blood root");
  set("long", "Blood root has long been used in concocting strong "
              "poisons and sedatives.  It is a fat root with reddish-"
              "brown skin.");
  set_weight(3+random(5));
  set_toxin_level(90+random(4));
  set_strength(5+random(4));
  crit_type = "paralysis";
  crit_level = "D";
}

