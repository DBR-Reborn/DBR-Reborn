#include <std.h>
#include <shao.h>

inherit ROOM;
void init(){
    ::init();
    add_action("kick_wall", "kick");
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("night light", 0);
    set("short", "alley");
set("long","%^BOLD%^This alley isn't very well lit, "
"but it is free from the usual garbage, crates, and boxes"
" you usually find in the Shao-tan back alleys...\n"
"It continues south, and you see the street to the north.\n"
"Buildings of various size and quality suround "
"this alley on the east, west, and southwest sides.\n");
set_items( ([
({"building","buildings"}):
"Looking around you see three of them...\n"+
"Two small wooden buildings, and a larger building "+
"to the northeast that looks to be made of stone.\n",
({"wooden buildings","small buildings",
"small wooden buildings","wood building","small building"
,"small wooden building"}):
"The wood buildings appeer to be the homes of "
"citizens...\n",
({"larger building","stone building","larger stone building"}):
"It looks very sturdy.\n"
]) );
    add_exit("sr3", "north");
add_exit("al3", "south");

set_smell("default","A musty, almost sweaty aroma lingers"
"in the air.\n");
set_listen("default","muffled sounds of music can just "
"barely be heard...\n");
}
