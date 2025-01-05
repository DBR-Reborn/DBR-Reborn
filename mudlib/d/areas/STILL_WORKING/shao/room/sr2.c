#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Southern Row");
set("night long","%^RESET%^An unlit dirt road "
"leads north into "
      "the darkness of night.  A Dim lantern sway from a street post "
"on the north western side of the street.  "
"Peering down the dimly lit street towards the west, you see "
"the west gate.\n"
"\n"
"This street appears to head deeper into the heart of the city, "
"if traveled east, while heading west will take you out of "
"the city.\n");
set("day long", "%^RESET%^%^ORANGE%^The sun "
"warms the cracked and worn cobble stones "
      "under yer feet.  An unlit lantern hangs on a light post on "
"the north western side of the street.  "
"Peering towards the east, Southern Row continues for quite"
" a distance.  Various buildings can be seen on either sides"
" of it.  In the oposite direction lies the west gate. "
"The side of an old wooden home is seen to the south, while "
"to the north lay a narrow dirt path.\n");
    add_exit("sr1", "west");
    add_exit("sr3", "east");
    add_exit("p17", "north");

set_listen("default", "Sounds of batter are heard in the distance "
"to the north.\n");

}
