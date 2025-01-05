/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("gangus root");
  set("id", ({"gangus root", "root"}) );
  set("short", "a few pieces of gangus root");
  set("long", "These roots are from the rare gangus vine, a plant usually "
              "impossible to find anywhere.  The roots are long and very "
              "narrow, resembling string.");
  set_weight(3+random(7));
  set_toxin_level(75+random(5));
  set_strength(4);
  crit_type = "blindness";
  crit_level = "D";
}
