#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Holy Row");
set("day long","You stand on a road made up entirely of "
"pure white inter locking marble bricks.  When "
"you look at what surounds it, it seems very out of place."
"  An ancient stone wall is directly south, and to the north "
"stands a section of the great wall of Shao-tan wich "
"protects the city from invaders.\n"
"\n"
"A marble plaque hangs from a shiny brass pole here...\n");
set("night long","Shiny brass lanters provide a "
"good amount of light, keeping the street well lit.  "
"To the south you see an ancient stone wall, that seems "
"very sturdy. To the north lay a section of the "
"great Shao-tan city wall.  You have a feeling of"
" inner peace and harmony for some reason.\n");
set_items(([
({"lanterns","brass lanterns","lantern","brass lantern"}):
"forged from brass and polished to a shine, the lanterns"
" have numerous symbols of a holy nature carved into them.",
({"wall","city wall","great wall","walls","section"}):
"it stands numerous feet tall, probably at least two or "
"three times taller then the tallest building in Shao-tan. "

"What seems to be the main purpose of the wall is that "
"guards standing on top of it have a clear view "
"of any invaders heading towards the city."
]));
    add_exit("hr5", "east");
    add_exit("hr3", "west");
if(query_night()){
set_smell("default","The odour of rotting flesh lingers "+
"in the night air.");
set_listen("default","You hear what you think is "+
"muffled moans and whines of agony.");
}
}
