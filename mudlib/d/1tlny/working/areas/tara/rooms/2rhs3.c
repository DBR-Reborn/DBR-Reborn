#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"
inherit ROOM;

void create() {
  ::create();
   set_property("light",2);
   set_property("night light",1);
   set_property("indoors", 1);
   set("short","The living room");
   set("day long", @DAY
The living room of Donny's house, it contains more trophies and
awards then it does furniture.  One couch sits next to a
small table.  A large bowl rests on the table, used for the ashes
of Donny's emptied pipes.  A thin flight of stairs lead down into
a spacious bedroom.  To the west is a dining room, and the entryway
is to the south.
DAY
);
   set("night long", @NIGHT
This is the living room of Donny.  It is barely lit, speaking
of the depression that has overtaken Donny.  Many trophies
and awards are in here, providing little comfort to their
owner.  A couch is next to a small table, the tables main purpose
being to hold a bowl for Donny's pipe ashes.  A thin flight of
stairs lead down into darkness.  To the west is a dining room, and
there is an entryway to the south.
NIGHT
);
   add_item("cough", "The couch looks comfortable, yet it has a "+
   "few burns on it.");
   add_item("burns", "Most likely burns from Donny's tabacco.");
   add_item("awards", "Many awards are nailed into the wall.");
   add_item("trophies", "Trophies adorn the room.");
   add_item("stairs", "A thin flight of stairs that leads down");
   set_smell("default", "It smells of tabacco.");
   set_listen("default", "It is still and quiet.");
   add_exit(TARAROOMS+"2rhs1", "south");
   add_exit(TARAROOMS+"2rhs5", "down");
   add_exit(TARAROOMS+"2rhs4", "west");
}
