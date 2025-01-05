inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

void create() {
  ::create();
   set_property("light",1);
   set_property("night light",0);
   set("short","Wide roadway");
   set("day long", @DAY
This roadway leads north to a fountain at the center of town,
and an odd looking building beyond that.  To the south is an
intersection, further south leads out of the town.  Busy halflings
frequent this road, getting there jobs down efficiently.  Plants
line the roadside here.
DAY
);
   set("night long", @NIGHT
It is extremely dark, only a few torches in the distance can be seen.
A small fountain lies to the north, beyond that only darkness.
Despite the darkness, you feel secure in this area of town, as
if no one would dare commit any crime around here.
NIGHT
);
   add_item("roadway","The villages main road.");
   add_item("fountain","The water supply of the halflings.");
   add_item("plants","Pretty flowers bloom on the plants.");
   add_item("flowers","All varieties have flowers are on the "+
   "plants");
   add_item("torches","Faint torches in the distance to the east "+
   "and west");
   add_item("building","A small one story building, with part "+
   "of it built into the hillside, part built outside.");
   set_listen("default","You hear a fountain to the north");
   set_smell("default","The smell of flowers fills the air.");
   add_exit(TARAROOMS+"rm2", "south");
   add_exit(TARAROOMS+"rm10", "north");
}
