#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Shadow Lane");
set("day long","%^RESET%^%^ORANGE%^A "
"dense fog covers the street "
"preventing you from being able to see the ground "
"on wich you stand.  To the north you notice that "
"the fog just seems to be sucked into the ground, "
"stoping it from flowing onto the other street.  "
"To the west you see an old wooden shack of some sort"
" while to the east lay a section of the great Shao-tan"
" city wall.  To the south the fog seems to thicken "
"a great deal.\n");
set("night long","%^RESET%^A dense fog layers the "
"street, almost totaly imparing vision.  You "
"can just barely make out two silhouettes to the "
"east and west that resemble buildings or walls of some sort."
"\n");
    add_exit("shad6", "south");
    add_exit("hr6", "north");
if(query_night()){
set_smell("default","The odour of rotting flesh lingers "+
"in the night air.");
set_listen("default","You hear what you think is "+
"muffled moans and whines of agony.");
}
}
