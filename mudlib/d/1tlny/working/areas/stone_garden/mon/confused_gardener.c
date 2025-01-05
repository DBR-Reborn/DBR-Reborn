 // Wizard: Shade Maelstorm //
 // Monster File: Confused Troll Gardener//
 
#include <std.h>
inherit MONSTER;
 
void create() {
object swrd;
object corslet;
   ::create();
  set_name("Troll Gardener");

  set("id", ({"gardener", "troll" }));
   set_level(5+random(5)+random(5));
set_skill("blunt", 75);
set_money("gold",  random(50)+30);
  set("short", "A Young Troll");
   set("long",
  "This is a young troll gardener, who is learning his gardening profession."
  "As usual an apprentice's first job is always to clean something, and this poor"
  "trolls job is to clean out the gardeners workshed."
   );
  set("race", "half-troll");
   set_overall_ac(30);
   set_gender("male");
   set_body_type("human");
   set_moving(0);
   set_speed(120);

 set_emotes(10, ({
  "The young troll shakes the dust off his cloth and continues cleaning."
  "With great care, the young gardener troll stands all the shovels together upright."
  "The young troll races around, thinking of what else he could clean."
  "Looking up at high window, the young troll sighs and goes back to his cleaning."
  "I'll never be able to clean that window, sigh, its too high. "
   }), 0);
swrd = new("/d/damned/virtual/short-sword_4.weapon");
  swrd->set_material("misc/wood");
  swrd->set("short", "wooden sword");
  swrd->set("long", "This is a wooden sword, normally given to young children, so "
  " they do not poke their eyes out. ");
  swrd->move(this_object());
force_me("wield wooden sword in right hand");

 corslet = new("/d/damned/virtual/corslet.armour");
corslet->set("short", "stone corslet");
corslet->set_material("/misc/granite");
corslet->move(this_object());
force_me("wear corslet");
}
 
 
