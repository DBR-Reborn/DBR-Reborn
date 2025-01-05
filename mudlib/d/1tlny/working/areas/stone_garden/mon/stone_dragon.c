 // Wizard: Shade Maelstorm //
 
 // Monster File: Stone Dragon //
#include <std.h>
#include <stone_garden.h>

inherit MONSTER;
 
void create() {
  object ob;
   ::create();
 set_property("no corpse",1);
  set_name("Stone dragon");
   set_level(5+random(5));
set("id", ({"dragon", "stone dragon" }));
  set_money("silver", random(50));
   set("short", "A stone dragon");
   set("long",

  "This is a magically animated statue of a large dragon. It seems to resemble some "
 "of the dragon statues you have seen in the garden, but somehow this one is alive. "
 "Its wings are quite broad, and amazingly swift given its stone construction. "
 "The dragon looks at you with cold black souless eyes, and watches your movements "
 "intently. ");
  set("race", "creature of stone");
   set_overall_ac(30);
   set_gender("neuter");
   set_body_type("human");


 
}
 
void die(object ob) {
  ::die();
  message("info", "The stone mage crumbles into a pile of rubble, and the magic contained inside the creature turns into a vapour and dissapates.",environment());
 }
