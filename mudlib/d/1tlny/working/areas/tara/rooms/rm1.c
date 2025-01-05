inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

void create() {
  ::create();
   set_property("light",2);
   set("short", "Branching roadway");
   set("day long", @DAY
A roadway just north of the entrance to town, it heads up the
hill this town is built in.  It branches into three directions,
North it heads into the center of town, where the Halflings
hang out and spend time socializing.  Northeast lies a
tavern, one of the only buildings above ground, and the poorer
district of the town.  Northwest is the richer section,  the
gardens well tended, larger yards.  Little Halflings travel
in and out, most of them in a hurry to get inside, away from
the sun.
DAY
);
   set("night long", @NIGHT
A roadway north of the town entrance, night shrouds most sections
of the town.  To the northeast, however, a large tavern, built
above ground, has torches to light the way.  Occasional houses
to the northwest have torches outside their doors.  Only
darkness can be seen to the north, the center of town.
NIGHT
);
   add_item("tavern","A large tavern, created for hard working "+
   "halflings to unwind.");
   add_item("town","The halfling's town you are entering.");
   add_item("garden","Beautiful gardens planted outside houses.");
   add_item("torches","Torches placed to light the dark night.");
   add_item("houses","The halflings houses are built into the hillside");
   add_item("hillside","A rolling hillside that the town is built upon");
   set_smell("default","The smell of fresh earth fills the air.");
   set_listen("default","You can hear the faint trickling of a fountain");
   add_exit(TARAROOMS+"entry", "south");
   add_exit(TARAROOMS+"rm2", "north");
   add_exit(TARAROOMS+"rm3", "northeast");
   add_exit(TARAROOMS+"rm4", "northwest");
}
