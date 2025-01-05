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
"a building of some sort, and to the east is a "
"dirt path.  "
"Each step you take on this holy path of marble seems "
"to give you a feeling of inner peace and harmony...\n"
"\n"
"A marble plaque hangs from a shiny brass pole here...\n");
set("night long","%^RESET%^Shiny brass lanterns "
"provide a "
"good amount of light, keeping the street well lit.  "
"To the west you see a building, and to the east"
" lay the start of a dirt path.  The marble street continues "
"north and south.  You have a feeling of inner "
"peace and harmony for some reason.\n");
set_items(([
({"lanterns","brass lanterns","lantern","brass lantern"}):
"forged from brass and polished to a shine, the lanterns"
" have numerous symbols of a holy nature carved into them.",
({"west wall","building","militia training center"}):
"The entrance to what looks like some sort of "
"training facility.",
]));
    add_exit("hr7", "north");
    add_exit("hr9", "south");
add_invis_exit("path");
add_exit("hos_garden","path");
if(!query_night()){
set_listen("default","Sounds of combat filter from the building "
"to the west");
}
}
