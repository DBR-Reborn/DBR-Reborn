#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "1st Street");
set("night long","%^RESET%^The oil lanterns "
"lining the street "
      "have been knocked over, leaving this small section of road darker "
      "then the rest of the busness district.\n");
set("day long","%^RESET%^%^ORANGE%^You stand "
"in the northern section of the busness district "
      "and are at the heart of Shao-tan.  "
      "The cobble stone streets are well maintained and as litter free as "
      "possible with the heavy traffic of patrons that travel it each day.  "
"The Shao-tan jail is just north of here, as well as "
      "the post office, and church to the far north.  The militia lodge"
      " and bank lay to the south.");
    add_exit("al9", "west");
    add_exit("al10", "east");
    add_exit("1st11", "north");
    add_exit("1st9", "south");
    add_invis_exit("west");
    add_invis_exit("east");

}
