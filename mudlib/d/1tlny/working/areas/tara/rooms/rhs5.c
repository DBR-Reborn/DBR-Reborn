inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"


void create() {
  ::create();
   set_property("light",1);
   set_property("night light",1);
   set_property("indoors", 1);
   set("short", "A circular room");
   set("day long", @DAY
This circular room is at the base of a stairway.  Three exits lead to
seperate rooms, which appear to be bedrooms.  The walls are painted in
unmatching bright colors, the kind of room only a halfling could love.
Torches are hooked into the wall, this place being to far into the hillside
for natural light to penetrate.
DAY
);
   set("night long", @NIGHT
This is an odd circular room, it presides at the base of a stairway,
and has three exits leading to other rooms.  This seems to be
around the sleeping quarters for the halflings of this house, for
no noise can be heard, and the lights are dim.  Only one torch is
lit in the entire lower area, making it impossible to see into the
other rooms.  The walls are painted in wierd colors that only a halfling
would love.
NIGHT
);
   add_exit(TARAROOMS+"rhs8", "southeast");
   add_exit(TARAROOMS+"rhs1", "up");
   add_exit(TARAROOMS+"rhs7", "southwest");
   add_exit(TARAROOMS+"rhs6", "northeast");
   add_item("stairway", "The stairway leads up into the other part of "+
   "the house");
   add_item("walls", "The walls are very unique.  Only a halfling could "+
   "enjoy the wierd mixture of colors");
   add_item("torches", "Plain ordinary torches.");
   add_item("torch", "A plain ordinary torch.");
   set_smell("default","The air smells of perfume.");
   set_listen("default","Some crying can be heard.");
}
