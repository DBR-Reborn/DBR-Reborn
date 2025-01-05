
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 3);
set_property("night light",1);
add_exit(ROOMS+"sewer1.c", "down");
add_exit(ROOMS+"ruins7.c", "up");
set("short", "City Sewers");
set("day long", "This is a manhole to the city sewers below. Nothing here put a ladder leading down into the sewers and a ladder leading up to the city above.");
set("night long", "This is a manhole to the city sewers below. Nothing here put a ladder leading down into the sewers and a ladder leading up to the city above.");
set_smell("default", "The cold wind feels like death on your skin");
set_listen("default", "It is extremely quiet.");
}
