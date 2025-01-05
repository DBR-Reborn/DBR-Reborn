#include <std.h>
#include <shao.h>

inherit VAULT;
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
"It continues to the east and west.\n"
"Buildings of various size and quality suround "
"this alley in all directions except east and west.  "
"The buildings to the north, south and north west "
"all have back doors facing this alley.\n");
set_items( ([
({"building","buildings"}):
"Looking around you see five of them...\n"+
"two small wooden buildings, one medium sized "+
"wooden building, and a larger building to the "+
"north and north east that look to be made of stone.\n",

({"wooden buildings","small buildings",
"small wooden buildings","wood building","small building"
,"small wooden building"}):
"The wood buildings appeer to be the homes of "
"citizens...\n",
({"door","doors"}):
"There is a north door, a south door and a northeast door.",
({"north door","northeast door"}):
"The heavy iron door looks very, very sturdy.",
({"south door"}):
"The heavy wood door doesn't appeer to have a visible lock.",
({"medium building","stone building","medium stone building"}):
"They both look very sturdy, a heavy iron door is "
"on the one to the north.\n"
]) );
    add_exit("al3", "west");
add_exit("al1", "east");
add_exit(PATH+"slut_ent","south");
add_exit(PATH+"lshop_br","north");
add_invis_exit("south");
add_invis_exit("north");
set_door("iron door",PATH+"lshop_br","north","master key");
set_open("iron door",0);
set_locked("iron door",1);
set_door("wooden door",PATH+"slut_ent","south",0);

set_smell("default","A musty, almost sweaty aroma lingers"
"in the air.\n");
set_listen("default","muffled sounds of music can just "
"barely be heard...\n");
}
