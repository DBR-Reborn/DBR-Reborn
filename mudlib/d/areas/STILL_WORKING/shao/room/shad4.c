#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Shadow Lane");
set("long","%^BOLD%^A dense fog layers the "
"street, almost totaly imparing vision.  You "
"can just barely make out two silhouettes to the "
"east and west that resemble buildings of some sort."
"\n");
    add_exit("shad3", "south");
    add_exit("nr9", "north");
if(query_night()){
set_smell("default","The odour of rotting flesh lingers "+
"in the night air, but your not sure from wich direction...\n");
set_listen("default","You hear what you think is "+
"muffled moans, and whines of aggony, but you "+
"can't pin point a direction");
}
}
