/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("jerup weeds");
  set("id", ({"weeds", "jerup weeds"}) );
  set("short", "a bunch of jerup weeds");
  set("long", "The jerup weed is a more destructive weed than its "
              "cousin, the yithki weed.  This plant has a long, thin "
              "stem, a small orange flower on top, and, like the yithki "
              "weed, has large, shiny leaves.");
  set_weight(3+random(5));
  set_toxin_level(25+random(3));
  set_strength(3);
}
