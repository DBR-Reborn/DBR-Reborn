inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

void create() {
  ::create();
   set_property("light",1);
   set_property("night light",0);
   set("short","Bench area");
   set("day long", @DAY
A small, enclosed area, it has benches for the halflings to relax.
Here is where families come to picnic, couples come to spend
time together, and friends gather to smoke some tabacco.  Like most
of the town, there are some plants here, brightening an already
lively area.  To the west is a small fountain, a bit farther then that
are more benches.
DAY
);
   set("night long", @NIGHT
This small area is completely void of light.  No one thought of
placing torches here.  A few wooden benches are here, no doubt more
popular during the day.  Some plants liven the small area.  To the east
somewhere are some torches.  You can hear a fountain to the west.
NIGHT
);
   add_item("benches","Some wooden benches, while not the greatest design, "+
   "they serve there purpose.");
   add_item("fountain","The towns water supply lies to the east.");
   add_item("plants","A variety of plants, placed and mantained here for "+
   "the pleasure of the towns citizens");
   set_listen("default","You hear a fountain to the west.");
   set_smell("default","The air smells fresh and clean.");
   add_exit(TARAROOMS+"rm10", "west");
}
