/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("marsig mushrooms");
  set("id", ({"marsig mushrooms", "mushrooms"}) );
  set("short", "a bunch of marsig mushrooms");
  set("long", "These large, brown and black mottled mushrooms grow "
              "in dark, damp places, usually under the low branches of "
              "fulma trees.");
  set_weight(3+random(10));
  set_toxin_level(44+random(5));
  set_strength(5+random(3));
  crit_type = "blindness";
  crit_level = "C";
}
