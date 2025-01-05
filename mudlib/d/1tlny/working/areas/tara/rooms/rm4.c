inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

void create() {
  ::create();
   set_property("light",2);
   set("short","A well made roadway");
   set("day long",  @DAY
You are on a well constructed roadway, leading to the richer 
section of town.  It seems the wealthy halflings care very much
about how their neighborhood appears.  Small gardens line the sides of
the path, beautifying the way towards the well off homes.  The houses
to the northwest have large well-tended gardens, and a large
spacious area built into the hillside.
DAY
);
   set("night long", @NIGHT
This well constructed roadway leads to the riches area of Tara.
Torches guide the way, the wealthy being able to afford to keep
them lit nightly.  Gardens along the roadside are complimented nicely
by the nights light.  Houses to the northwest also have torches outside
their doors, allowing them easy access to their homes late a night.
NIGHT
);
   add_item("torches","Torches funded by the well off halflings "+
   "light the way.");
   add_item("gardens","Pretty well tended gardens, the compliment "+
   "the upper class section of town.");
   add_item("houses","Fancy looking houses, which take a good portion "+
   "of the hillside.");
   set_smell("default","The air smells of fresh flowers.");
   set_listen("default","It is quite and peaceful.");
   add_exit(TARAROOMS+"rm1", "southeast");
   add_exit(TARAROOMS+"rm8", "northwest");
}
