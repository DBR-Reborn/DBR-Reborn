#include <dirs.h>
#include <std.h>
#include "../monk.h"
inherit ROOM;

void create() {
  ::create();
   set_property("light",2);
   add_exit(MONKROOMS+"room25", "south");
   add_exit(MONKROOMS+"room23", "east");
   set("short","Village path   \n     \n   @--0\n   | \n   0\n");
   set("long",
"This is a village path leading west to the monks meditation "
"area.  The path bends south to reveal a large area "
"cleared out for the monks.  To the east is the rest of "
"of the village.   \n     \n   @--0\n   | \n   0\n");
   add_item("path","A path leading to the western outskirts of town.");
}
void reset() {
  ::reset();
   if(!present("monk"))
   new(MONKMOBS+"monk2.c")->move(this_object());
   if(!present("gardener"))
   new(MONKMOBS+"monk_gardener.c")->move(this_object());
}

