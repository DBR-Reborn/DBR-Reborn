#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Holy Row");
set("day long","%^RESET%^%^ORANGE%^This marble "
"road is made of almost "
"entirly pure white marble bricks. To the west is "
"a stone wall, and to the east is a building of some sort.  "
"Each step you take on this holy path of marble seems "
"to give you a feeling of inner peace and harmony...\n"
"\n"
"A marble plaque hangs from a shiny brass pole here...\n");
set("night long","%^RESET%^Shiny brass lanterns "
"provide a "
"good amount of light, keeping the street well lit.  "
"To the east you see a building, and to the west"
" lay a brick wall.  The marble street continues "
"north and south.  You have a feeling of inner "
"peace and harmony for some reason.\n");
set_items(([
({"lanterns","brass lanterns","lantern","brass lantern"}):
"forged from brass and polished to a shine, the lanterns"
" have numerous symbols of a holy nature carved into them.",
({"stone-bricked wall","stone wall","brick wall","west wall"}):
"A solid looking wall built from bricks of stone...\n",
({"wall","walls"}):
"There are two of them, one to the west, wich is brick, and "
"one to the east.",
({"east wall","building","hospital"}):
"The side of a building wich you suspect is a place of "
"healing is to the east. It is made of stone.\n",
]));
    add_exit("hr1", "north");
    add_exit("hr8", "south");
if(!query_night()){
set_listen("default","Sounds of combat filter over the wall to the west");
}
}
