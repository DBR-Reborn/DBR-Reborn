/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("geckin twigs");
  set("id", ({"geckin twigs", "twigs"}) );
  set("short", "a handful of geckin twigs");
  set("long", "These small grayish twigs are from the branches of the "
              "short, rare geckin tree.  It is said that these twigs can "
              "be used to create both curative and poisonous substances.");
  set_weight(3+random(5));
  set_toxin_level(55+random(4));
  set_strength(3);
}
