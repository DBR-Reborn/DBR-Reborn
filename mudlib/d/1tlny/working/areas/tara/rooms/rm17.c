inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

void create() {
  ::create();
   set_property("light",2);
   set_property("night light",1);
   set("short","Commercial area");
   set("day long", @DAY
This is the entrance to the commercial section of Tara, the
road branches northeast and northwest, leading down two seperate lanes
of shops.  To the immediate north is one of the only buildings in the
town that is not built fully into the hillside.  Looking in, it
appears to be some kind of law enforcement building.  To the south
is a fountain.
DAY
);
   set("night long", @NIGHT
In the entrance to the towns commercial area, most of the buildings
are locked up and closed.  One however, to the immediate north, is still
open at this late hour.  That building is also odd in the fact that
it's halfway built outside.  You can make out the shape of a fountain to
the south.
NIGHT
);
   add_item("fountain","The towns main water source lies to the south");
   add_item("building","The building immediately north appears to be "+
   "some kind of law enforcement building, perhaps a jail.");
   add_item("commercial area","This is where all the towns shops are "+
   "located");
   add_item( "area","This is where all the towns shops are "+
   "located");
   set_smell("default","It smells like bacon.");
   set_listen("default","The sounds of a busy town fill the air");
   add_exit(TARAROOMS+"rm10", "south");
   add_exit(TARAROOMS+"rm18", "northwest");
   add_exit(TARAROOMS+"jail", "north");
}
