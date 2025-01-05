#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"
inherit VAULT;

void create() {
  ::create();
   set_property("light",2);
   set_property("night light",2);
   set_property("indoors", 1);
   set_door("engraved door", TARAROOMS+"rm24", "east", 0);
     set_open("engraved door", 0);
     set_locked("engraved door", 0);
   set("short","The entryway");
   set("day long", @DAY
This is the entryway of Donny's home.  His wooden door
is engraved with a large pipe, and a few windows look out into
the town.  Some shelves are built into the walls, they are filled
with all kinds of fancy nick-nacks.  To the west if a kitchen, and
north is the living room.
DAY
);
   set("night long", @NIGHT
The entryway to Donny's home, a few torches are lit to
keep the house easy to walk along.  The large wooden door that
leads out is engraved with a pipe, and a few windows look out into
the town.  Some shelves containing expensive nick-nacks are built
into the walls, Donny liking to show off his riches.  To the west
is a kitchen, and to the north is the living room.
NIGHT
);
   add_exit(TARAROOMS+"2rhs2", "west");
   add_exit(TARAROOMS+"2rhs3", "north");
   add_exit(TARAROOMS+"rm24", "east");
   add_item("door", "The door is engraved with a large pipe, a symbol "+
   "of the owners hobby and passtime.");
   add_item("shelves", "The shelves are built into the wall, and "+
   "contain costly nick-nacks of all sorts.");
   add_item("windows", "Windows that provide a lovely veiw of "+
   "the town");
   set_smell("default","The smell of cooking food wafts in from the west");
   set_listen("default","The house is depressingly quiet.");
}
