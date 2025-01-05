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
"entirly pure white marble bricks. To the east is "
"a building of some sort, and to the west is "
"the front steps of Shao-tan city hall.  "
"The road continues to the north, to the south you see "
"what looks like a section of Northern Row.  "
"Each step you take on this holy path of marble seems "
"to give you a feeling of inner peace and harmony...\n"
"\n"
"A marble plaque hangs from a shiny brass pole here...\n");
set("night long","%^RESET%^Shiny brass lanterns "
"provide a "
"good amount of light, keeping the street well lit.  "
"To the east you see a building, and to the west"
" lay the front steps of Shao-tan city hall.  "
"The marble street continues "
"north and to the south looks like a section of "
"Northern Row. You have a feeling of inner "
"peace and harmony for some reason.\n");
set_items(([
({"lanterns","brass lanterns","lantern","brass lantern"}):
"forged from brass and polished to a shine, the lanterns"
" have numerous symbols of a holy nature carved into them.",
({"west wall","building","militia training center"}):
"The entrance to what looks like some sort of "
"training facility.",
]));
    add_exit("hr8", "north");
    add_exit("nr5", "south");
add_exit(PATH+"CH_steps","west");
if(!query_night()){
set_listen("default","Sounds of combat filter from the building "
"to the west");
}
}
