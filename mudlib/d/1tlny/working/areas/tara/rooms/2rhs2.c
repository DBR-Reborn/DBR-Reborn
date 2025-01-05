#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"
inherit ROOM;

void create() {
  ::create();
   set_property("light",2);
   set_property("night light",1);
   set_property("indoors", 1);
   set("short","The kitchen");
   set("day long", @DAY
The kitchen is clean and spotless, the hired help doing an extremely
good job on keeping it sanitary after they cook the meals.
Aside from the ordinary kitchen tools, this room is boring
and average.  One window looks out into the town.  The entryway
is to the east, and a dining room to the north.
DAY
);
   set("night long", @NIGHT
One torch lights the kitchen, displaying how clean it is.  The
cooks do a very good job cleaning it after they are done cooking
meals.  The room is void of anything interesting, just containing
the regular tools most kitchens have.  A lone window looks out
into the starlit town.  To the north is the dining room, and
the entryway is to the east.
NIGHT
);
   add_exit(TARAROOMS+"2rhs4", "north");
   add_exit(TARAROOMS+"2rhs1", "east");
   add_item("tools", "Plain boring kitchen tools.");
   add_item("window", "The window looks out over Tara.");
   set_smell("default","It smells of delicious food.");
   set_listen("default","You can hear hard working cooks.");
}
