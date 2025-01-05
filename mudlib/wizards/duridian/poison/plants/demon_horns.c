/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("demon horns");
  set("id", ({"demon horns", "horns", "thorns"}) );
  set("short", "a couple demon horns");
  set("long", "Demon horns are the large, sharp thorns from the thrukus "
              "vine, sometimes called the \"demon vine\" because of its "
              "long thorns.");
  set_weight(3+random(5));
  set_toxin_level(97+random(4));
  set_strength(5);
  crit_type = "blindness";
  crit_level = "E";

}

