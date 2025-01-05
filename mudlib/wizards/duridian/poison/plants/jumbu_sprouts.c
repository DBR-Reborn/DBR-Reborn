/*
   Plant coded by Duridian for DarkeMud.
   This plant is used for creating poisons with a plant press.
*/
 
inherit "/wizards/duridian/poison/poisonous_plant";
 
void create() {
  ::create();
  set_name("jumbu sprouts");
  set("id", ({"sprouts", "jumbu sprouts"}) );
  set("short", "a small handful of jumbu sprouts");
  set("long", "The red and green jumbu sprouts usually are found on the "
              "edge of the great plain that lies north of Akkad.  The "
              "individual sprouts are very small and very delicate.");
  set_weight(3+random(5));
  set_toxin_level(43+random(4));
  set_strength(5);
}
