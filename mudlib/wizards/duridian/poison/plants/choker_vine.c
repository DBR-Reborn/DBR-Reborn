/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("choker vine");
  set("id", ({"choker vine", "vine"}) );
  set("short", "a few strands of choker vine");
  set("long", "The choker vine is a brown vine with long thorns that "
              "protrude from the tough skin of the plant.  A few small, "
              "pointed, black leaves also adorn this rather ugly plant.");
  set_weight(3+random(5));
  set_toxin_level(60+random(4));
  set_strength(5+random(4));
  crit_type = "paralysis";
  crit_level = "E";
  set_value(200);
}

