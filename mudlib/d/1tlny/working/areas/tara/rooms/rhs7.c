inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"


void create() {
  ::create();
   set_property("light",1);
   set_property("night light", 1);
   set_property("indoors", 1);
   add_exit(TARAROOMS+"rhs5", "northeast");
   set("short", "A nursery");
   set("day long", @DAY
This is where the halflings small children are taken care of, and stay.
A few cribs rest against the far wall, the place where screaming
babies are put to bed.  Aside from another small bed, and assorted toys,
this room is barren of any kind of fancy furniture that would be
expected in a rich home.
DAY
);
   set("night long", @NIGHT
This is the nursery where the halflings have their children taken
care of.  There are a few cribs which rest against the wall, and a small
bed in a corner.  Assorted toys adorn the floor, leaving little space
for walking.  The only light here is what filters in from the torch
outside the room.
NIGHT
);
   add_item("cribs", "The ultimate trap for screamy whiny rich brats");
   add_item("bed", "It looks to be the bed of someone who has graduated "+
   "from the cribs");
   add_item("toys", "Toys litter the ground everywhere, this whole "+
   "room appears to be a large playpin.");
   set_smell("default","It smells like poop and urine.");
   set_listen("default","The cries of babies can be heard");
}
void reset() {
  ::reset();
   if(!present("baby")){
   new(TARAMON+"baby")->move(this_object());
   new(TARAMON+"baby")->move(this_object());
   }
   if(!present("toddler")){
   new(TARAMON+"toddler")->move(this_object());
   }
}
