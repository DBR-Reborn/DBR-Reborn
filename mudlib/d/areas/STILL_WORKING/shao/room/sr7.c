#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Southern Row");
set("night long", "%^RESET%^A smashed lantern "
"lay at your feet.\n"
      "This section Southern Row is very dark, if not for the dim light "
"given off by the stars that dot the sky, it "
      "would be totaly dark. You can just barely make out the small "
      "street sign that reads:\n"
      "\n"
      "Southern Row with arrows pointing to the east and west");
set("day long","%^RESET%^%^ORANGE%^A broken "
"street lantern lay at your feet, "
      "the sharp glass not yet cleaned up by the Shao-tan care-takers.  "
"The front of an old abandoned shop lay to the north.  "
"To the west you see some buldings that appeer to be shops "
"of some sort.  To the far west, although its some distance "
"away, you can see the shiny blade of the guillotine.\n"
"\n"
"Southern Row continues both west deeper into the city and "
"east towards a city gate.\n");
add_exit("sr6", "west");
add_exit("sr8", "east");
add_exit("al14", "south");
add_exit("al13", "north");
add_invis_exit("south");
add_invis_exit("north");

}
