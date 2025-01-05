#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Holy Row");
set("day long","%^RESET%^%^ORANGE%^You stand on "
"a road made up entirely of "
"pure white inter locking marble bricks.  When "
"you look at what surounds it, it seems very out of place."
"  A stone-bricked wall stands to the west, and to the north "
"stands a section of the great wall of Shao-tan wich "
"protects the city from invaders.\n"
"\n"
"A marble plaque hangs from a shiny brass pole here...\n");
set("night long","%^RESET%^Shiny brass lanterns "
"provide a "
"good amount of light, keeping the street well lit.  "
"To the south you see an old wooden shack, that seems "
"out of place. To the north lay a section of the "
"great Shao-tan city wall.  You have a feeling of"
" inner peace and harmony for some reason.\n");
set_items(([
({"lanterns","brass lanterns","lantern","brass lantern"}):
"forged from brass and polished to a shine, the lanterns"
" have numerous symbols of a holy nature carved into them.",
({"stone-bricked wall","stone wall","brick wall","west wall"}):
"A solid looking wall built from bricks of stone...\n",
({"wall","walls"}):
"There are two of them, one to the west, wich is brick, and "
"one to the north.",
({"city wall","great wall","north wall","section"}):
"it stands numerous feet tall, probably at least two or "
"three times taller then the tallest building in Shao-tan. "

"What seems to be the main purpose of the wall is that "
"guards standing on top of it have a clear view "
"of any invaders heading towards the city."
]));
    add_exit("hr2", "east");
    add_exit("hr7", "south");
if(!query_night()){
set_listen("default","Sounds of combat filter over the wall to the west");
}
}
