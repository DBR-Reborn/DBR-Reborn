 // Wizard: Shade Maelstorm //
// Monster File: Stone Gargoyle.c loads into sg_room5.c and patrols attacking all
//in the garden who do not wear the acolyte amulet.
 
#include <std.h>
inherit MONSTER;
 
void create() {
   ::create();
  set_name("Gargoyle");

  switch(random(3)) {
   case 0:set_cmd_array(({"east", "north", "east", "north", "east", "north", "south",
 "east", "south", "east", "south", "east", "west", "south", "west", "south", "west",
 "west", "north", "west", "north", "west"}));

 break;

case 1:set_cmd_array(({"east", "south", "east", "south", "east", "east", "north", "east",
 "north", "east", "west", "north", "west", "north", "west", "north", "south", 
 "west", "south", "west", "south", "west"}));

 break;

case 2:set_cmd_array(({"east", "east", "north", "north", "south", "east", "south", 
 "east", "south", "west", "west", "west"}));

break;
 }

  set_cmd_interval(20);
  set_cmd_cycle(1);
   set("id", ({"gargoyle"}));
   set_level(5+random(5)+random(5));
set_skill("blunt", 75);
set_money("gold",  random(50)+30);
  set("short", "A Gargoyle");
   set("long",
  "This creature of stone is a gargoyle. You seem remember very very similiar statues "+
 "of such things, in the more quiet areas of the gardens. Its huge claws are extremely "+
 "powerful, and it is said they can cleave solid stone with them. Its wings move "+
 "as it walks, and are quite wide in terms of wingspan. It is truely a horrifying "+
 "creature, and what makes it worse, is that it seems to be grinning at you evilly. "+
 "Somehow, i dont think it has your best interests at heart. ");
  set("race", "gargoyle");
   set_overall_ac(30);
   set_gender("male");
   set_body_type("dragon");
   set_moving(1);
   set_speed(120);

}
 
 
