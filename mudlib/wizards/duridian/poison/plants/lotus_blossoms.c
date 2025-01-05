/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("lotus blossoms");
  set("id", ({"blossoms", "lotus blossoms"}) );
  set("short", "a pair of lotus blossoms");
  set("long", "In your hand are two beautiful lotus blossoms.  These "
              "flowers are very rare in this land because of the harsh "
              "climate and generally poor soil.");
  set_weight(3+random(3));
  set_toxin_level(70+random(3));
  set_strength(4);
}
