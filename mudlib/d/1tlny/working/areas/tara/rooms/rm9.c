inherit "std/vault";
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

void create() {
  ::create();
   set_property("light",2);
   set_property("night light",2);
   set_door("wooden door", TARAROOMS+"rhs1", "west", 0);
     set_open("wooden door", 0);
     set_locked("wooden door", 0);
   set("short","A residential street");
   set("day long", @DAY
You are on a residential street which leads north, outside of the
wealthy homes.  There is a house to the west, a wooden door, and round
windows sticking out of the hillside are about all that can be seen
of it.  A beautiful garden surrounds the area, possibly tended by
poorer halflings needing work.  There are about four more houses
of this quality to the north, before the street ends.
DAY
);
   set("night long", @NIGHT
You are on an extremely well lit street, torches light the surrounding
area, making it appear almost daytime.  To the west is a house,
it's wooden door and round windows made by quality craftsmen, displaying
the fact that it belongs to a wealthy halfling.  To the north, the street
continues alongside more expensive houses.  Gardens of great
beauty are planted outside these houses, most likely tended by poorer
people in need of work.
NIGHT
);
   add_item("wooden door","A nicely fashioned wooden door, it leads "+
   "into a house.");
   add_item("street","A well paved street leading to other "+
   "wealthy homes.");
   add_item("torches","Torches provided by well off halflings, to "+
   "keep their neighborhood well lit at night.");
   add_item("gardens","Pretty well designed gardens.");
   add_item("house","The house to the west is obviously owned "+
   "by a wealthy halfling.");
   add_item("windows","Round windows, well crafted and sturdy.");
   add_item("houses","More houses lie along the street to the north");
   set_smell("default","The air smells faintly of food.");
   set_listen("default","A few distance voices can be heard inside "+
   "the houses");
   add_exit(TARAROOMS+"rhs1", "west");
   add_exit(TARAROOMS+"rm8", "southeast");
   add_exit(TARAROOMS+"rm24", "north");
}
