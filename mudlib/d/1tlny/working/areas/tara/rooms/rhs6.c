inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"


void create() {
  ::create();
   set_property("light",1);
   set_property("night light",1);
   set_property("indoors", 1);
   set("short", "A large bedroom");
   add_exit(TARAROOMS+"rhs5", "southwest");
   set("day long", @DAY
This is the houses main bedroom, the room is large and spacious,
offering luxery to those who abide here.  A large bed occupies the
center of the room, with nightstands put on either side.  A
large cabinet if also here, used for storing the clothes of the
rich halflings.  There is one lit torch to keep the place from
complete darkness, as it is too far from the surface to recieve
natural light.
DAY
);
   set("night long", @NIGHT
The houses largest bedroom, it consists of a large bed, a few
nightstands, and a large cabinet.  A small torch has been lit as
a night light, for the rich snobs who live here.  To the southwest
is a circular room.
NIGHT
);
   add_item("bed", "A large comfortable looking bed, no expenses "+
   "spared");
   add_item("nightstands", "A few nightstands for setting odds and "+
   "ends");
   add_item("cabinet", "A cabinet used for storing clothing that "+
   "only a rich halfling would want to wear.");
   set_smell("default","The air smells of perfume");
   set_listen("default","A few snores can be heard");
}
