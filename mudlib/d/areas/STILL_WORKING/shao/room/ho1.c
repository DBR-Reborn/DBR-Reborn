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
set("short","abandoned house");
set("long","%^BOLD%^This looks like it used to be "
"somebody's house, but all the furniture is gone."
"  The floors have been covered with large slates of "
"flat rocks, and the wooden walls are bare.  You notice a "
"solid looking laen door to the south, and an old heavy wooden "
"door to the north.\n");
set_items( ([
({"door","doors"}):
"There is a wooden door to the north and a "+
"solid looking laen door to the south",
({"north door","wooden door"}):
"An old heavy wooden door, possibly made of oak",
({"laen door","south door"}):
"It looks very, very sturdy, and oddly enough it has "+
"no handle or visible way to pull it open...\n"
"The heavy iron door looks very, very sturdy.",
]) );
add_exit(PATH+"slut_ent","north");
set_listen("default","Sounds of music, laughter, moans "
"and screams filter through the laen door");
}
