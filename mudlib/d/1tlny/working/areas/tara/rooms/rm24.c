#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"
inherit VAULT;

void create() {
  ::create();
   set_property("light",2);
   set_property("night light",2);
   set_door("engraved door", TARAROOMS+"2rhs1", "west", 0);
     set_open("engraved door", 0);
     set_locked("engraved door", 0);
   set("short","A residential street");
   set("day long", @DAY
You are walking along a well paved residential street.  It leads
north and south outside of the houses of the wealthy halflings of
Tara.  To the west is a house, all that can be seen of it is
a few windows, and a wooden door with a pipe engraved in it.
A few well groomed and tended tabacco plants have been planted
into a large garden outside this home.  There are some more houses
to the north, and one to the south.
DAY
);
   set("night long", @NIGHT
This residential street is well lit in the twilight hours,
it is obviously the upper class section of town.  There is a
house to the west, the only visible parts are a few windows
sticking out of the hill, and an odd wooden door with a pipe engraved
into it.  A large garden spreads around the area, a few
tabacco plants have been added to it.  To the north and south
are some more houses, all having torches outside to light the
night.
NIGHT
);
   add_item("houses", "Houses of the rich aline this street.");
   add_item("street", "A well paved lane which runs alongside houses.");
   add_item("house", "The house to the west has a door with "+
   "a pipe engraved in it");
   add_item("windows", "Small round windows stick out of the hill.");
   add_item("garden", "A nice garden, with a few tabacco plants "+
   "in its midst.");
   add_item("plants", "The plants are not yet ready to produce "+
   "tabacco leaves.");
   set_smell("default","It smells of tabacco.");
   set_listen("default","It is peaceful and quiet.");
   add_exit(TARAROOMS+"2rhs1", "west");
   add_exit(TARAROOMS+"rm9", "south");
}
