inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

void create() {
  ::create();
   set_property("light",2);
   set_property("night light",2);
   set("short","A well made roadway");
   set("day long", @DAY
The roadway leads northwest, soon changing into a residential street.
Gardens line the sides of the road, displaying the care the wealthy
halflings have in their neighborhood.  The houses are large and fancy, all
built into the hillside.
DAY
);
   set("night long", @NIGHT
The well made road changes into a street a little farther northwest,
the houses of the rich lining it.  Torches light the way, leaving
it at bright as day.  Pretty gardens abide on the sides of the road,
making the walk to the upper class section pleasant.  The houses
are all large and well constructed, built deep into the hillside.
NIGHT
);
   add_item("door","The wooden door stands open.");
   add_item("road","The road is well constructed and easy to "+
   "walk on.");
   add_item("torches","Many torches light the way in this area "+
   "of town.");
   add_item("houses","All the houses on the street are large, "+
   "and fancy.");
   add_item("street","A street to the northwest leads outside "+
   "the rich halflings houses.");
   add_item("gardens","Pretty gardens that add life to this area.");
   set_smell("default","The air smells of fresh plant life");
   set_listen("default","It is silent and peaceful.");
   add_exit(TARAROOMS+"rm4", "southeast");
   add_exit(TARAROOMS+"rm9", "northwest");
}
