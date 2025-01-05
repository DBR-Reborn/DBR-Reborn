#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Southern Row");
set("night long","%^RESET%^An old abandoned "
"building lay "
"to the north, you suspect it may have been a shop many years "
"ago.  The dark street seems to continue east and west from here"
".  It looks to be almost totaly dark to the west, yet "
"some light from the east gate keeps the street from "
"being swallowed by the night. "
"To the south lay a really large building.\n");
set("day long","%^RESET%^%^ORANGE%^The sun "
"warms the cracked and worn cobble stones "
      "under yer feet.  An unlit lantern hangs on a light post on "
"the north western side of the street.  "
"Peering towards the west, Southern Row continues for quite"
" a distance.  Various buildings can be seen on either sides"
" of it.  In the oposite direction lies the east gate. "
"The side of an old wooden building is seen to the south, while "
"to the north lay what looks like an old abandoned shop.\n");
    add_exit("sr7", "west");
    add_exit("sr9", "east");

set_smell("default","If your not mistaken, you smell shit..the "
"odour is strongest when you face south.");

}
