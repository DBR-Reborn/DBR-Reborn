inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"


void create() {
  ::create();
   set_property("light",3);
   set_property("night light",1);
   set_property("indoors", 1);
   set("short","Dining room");
   set("day long", @PENIS
You are standing inside a large dining room.  A table made of
treated wood resides in the middle of the room.  Six chairs surround
the table, proving that either a large family lives here, or they get
dinner guests often.  To the south is an entryway, and west looks to
be the kitchen.  Some round windows look out into the front yard.
PENIS
);
   set("night long", @VAGINA
You are inside a large comfortable dining room, candles light a
table in the middle of the room, leaving it dark and shaded.  Some
chairs surround the stable, made of treated wood, and cushioned for
comfort.  To the south is the entry room, and west looks like the
kitchen.  Small round windows over look the front yard.
VAGINA
);
   add_item("table", "A large table, made of treated wood, it "+
   "has six chairs surrounding it.");
   add_item("chairs", "Comfortable cushioned chairs reside around a table.");
   add_item("windows", "Small round windows, they look out into "+
   "the wrong yard, and in the distance, the town.");
   set_smell("default","It smells of delicious food");
   set_listen("default","Quite polite conversation can be heard.");
   add_exit(TARAROOMS+"rhs1", "south");
   add_exit(TARAROOMS+"rhs3", "west");
}
