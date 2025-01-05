 // Wizard: Shade Maelstorm //
 
 // Monster File: Mother Basilisk //
#include <std.h>
#include <stone_garden.h>

inherit MONSTER;
 
void create() {
  object ob;
   ::create();
 set_property("no corpse",1);
  set_name("Stone Mage");
   set_level(5+random(5));
set("id", ({"mage", "stone mage" }));
  set_money("silver", random(50));
   set("short", "A stone mage");
   set("long",

 "This is a magically animated statue of a magician. It appears to be like the "
 "mage statue, you saw earlier on in the garden, but somehow this one is moving. "
 "He looks in your direction and then ignores you totally, as if you were "
 "to below him in caste. "
   );
  set("race", "creature of stone");
   set_overall_ac(30);
   set_gender("neuter");
   set_body_type("human");


 
}
 
void die(object ob) {
 ::die();
  message("info", "The stone mage crumbles into a pile of rubble, and the magic contained inside the creature turns into a vapour and dissapates.",environment());
 }
