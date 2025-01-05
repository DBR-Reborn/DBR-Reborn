inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

void create() {
  ::create();
   set_property("light",2);
   set_property("night light",1);
   set("short", "Wide roadway");
   set("day long", @DAY
This wide roadway leads north towards the center of Tara.
A fountain is visible a little further on, a place for
halflings to get there daily water, and socialize with others
from this town.  Farther north is a strange looking building,
partialy outside, and partial under the hill.  Citizens 
use this road as the main way to get around town.  There are a few
plants along the roadside.
DAY
);
   set("night long", @NIGHT
A large roadway leading north into darkness, no one seems
to have bothers to place torches around the center of town.
You can make out the shape of a fountain to the north, and a
strange building further away.  Not many people are out
this late at night.
NIGHT
);
   add_item("roadway","The roadway leads north to the center "+
   "of town");
   add_item("fountain","The fountain is the villages "+
   "water source");
   add_item("plants","Upon closers inspection they appear "+
   "to be tabacco plants.");
   add_item("building","The building looks out of place and "
   "unusual for this town.");
   set_listen("default","You can hear a fountain.");
   set_smell("default","The air smells fresh and clean.");
   add_exit(TARAROOMS+"rm1", "south");
   add_exit(TARAROOMS+"rm7", "north");
}
