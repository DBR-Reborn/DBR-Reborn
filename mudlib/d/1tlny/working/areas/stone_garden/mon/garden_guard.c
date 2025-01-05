 // Wizard: Shade Maelstorm //
// Just a reminder to myself. Need to set it so it changes path each time it
// returns to its main guard post. Was hoping to get them to patrol together but
// i just realised they wont. ah well :)
 // need to adjust the monster file for this. This file is for the guards which
 
#include <std.h>
inherit MONSTER;
 
void create() {
object hammer;
object corslet;
   ::create();
  set_name("Guard");

    set("id", ({"guard"}));
  switch(random(3)) {
  case 0:set_cmd_array(({"west", "north", "west", "north", "east", "east", "east",
 "west", "south", "west", "south", "west"}));
 break;

 case 1:set_cmd_array(({"west", "north", "west", "north", "west", "east", "north", 
 "east", "north", "east", "north", "northwest", "north", "west", "north", "east",
 "east", "southwest", "south", "southeast", "south", "east", "south", "east", "south",
 "east", "west", "south", "west", "south", "west"}));
break;
 
 case 2:set_cmd_array(({"east", "north", "east", "north", "east", "west", "north",
 "west", "north", "west", "north", "northwest", "north", "west", "north", "east",
 "east", "southwest", "south", "southeast", "south", "west", "south", "west", "south",
 "west", "east", "south", "east", "south", "east"}));
break;
 case 3:set_cmd_array(({"east", "north", "east", "north", "east", "west", "west", 
 "west", "west", "east", "south", "east", "south", "east"}));
break;
}
 set_cmd_interval(20);
 set_cmd_cycle(1);
  set_level(10+random(10));
set_skill("blunt", 75);
set_money("gold",  random(50)+30);
  set("short", "Guard of the Rose");
   set("long",
  "This guard is one of the guards assigned to protect the stone garden. He is quite "+
"well built and wears a strange cloak over his armour which has a rose image on it. "+
 "The rose however is not red, but grey. How odd.");
  set("race", "high-man");
   set_overall_ac(30);
   set_gender("male");
   set_body_type("human");
   set_moving(0);
   set_speed(120);

hammer = new("/d/damned/virtual/hammer_5.weapon");
  hammer->set_material("misc/granite");
  hammer->set("short", "stone hammer");
  hammer->set("long", "This is a large stone hammer used for chiseling stone. It is "
   " quite heavy and looks like it could inflict quite a bit of damage. ");
  hammer->set_wc(20, "crushing");
  hammer->move(this_object());
force_me("wield hammer in right hand");

 corslet = new("/d/damned/virtual/corslet.armour");
corslet->set("short", "stone corslet");
corslet->set_material("/misc/granite");
corslet->move(this_object());
force_me("wear corslet");
}
 
 
