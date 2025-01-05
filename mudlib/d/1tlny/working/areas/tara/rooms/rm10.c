inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

void create() {
  ::create();
   set_property("light",1);
   set_property("night light",0);
   set("short","Center of Tara");
   set("day long", @DAY
This is the center of town, halflings come here to meet with friends,
replenish their water supply, pick up on cute halfling females,
and picnic.  A small fountain is here, the towns one and only water
supply.  To the north a ways, is a strange building that stands out,
it is built halfway outside, halfway under the hill.  The road
branches northeast and northwest when it hits the building, leading
to the towns commercial area.  A beautiful garden has been planted
near the fountain, a large oak tree marking the center.
To the east and west are some benches.
DAY
);
   set("night long", @NIGHT
This is the center of town, in the darkness you can make out
a small fountain.  During the day, this is where halflings come
to enjoy outdoors, and each others presence.  Down the road to
the north is a strange building, still open this late for some reason.
A pretty garden is planted around an oak tree, adding to the
pleasant asmosphere here.  There are benches to the east and west.
NIGHT
);
   add_item("building","An odd, out of place building, the outside "
   "of it gives no clue as to what it is.");
   add_item("road","The road continues north until it hits the "
   "building, then branches northeast and northwest to the shops "
   "and stores.");
   add_item("garden","The halflings must take pride in there town, "
   "the garden is well-tended and taken care of.");
   add_item("benches","Wooden benches for tired people to rest "
   "are to the east and west.");
   add_item("tree","A large oak tree surrounded by a garden");
   set_listen("default","The sound of the fountain is almost drowned "
   "out by the conversations going on.");
   set_smell("default","The air is fresh, and the garden smells lovely");
   add_exit(TARAROOMS+"rm7", "south");
   add_exit(TARAROOMS+"rm11", "west");
   add_exit(TARAROOMS+"rm12", "east");
   add_exit(TARAROOMS+"rm17", "north");
}
void reset() {
   if(!present("fountain")) {
   new(TARAOBJ+"well.c")->move(this_object());
   }
}
