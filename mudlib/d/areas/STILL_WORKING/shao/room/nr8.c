#include <std.h>
#include <shao.h>
#include <daemons.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Northern Row");
set("night long","%^RESET%^This section "
"of Northern Row is "
"very calm and quiet.  An ancient stone wall stands to the north, "
"its probably as old as the spirits that lay beyond it.  "
"Soft candle light can be seen comming from the building to the "
"south.\n"
"\n"
"The street continues both east and west...\n");
set_smell("default", "The stale stench of death lingers in "
"the air");
set_listen("default", "Very faint moans and shreeks can be heard "
"beyond the wall to the north.\n");
set("day long", "%^RESET%^%^ORANGE%^The "
"cobble stones of the street are "
"damp and cold as ice.  An old wooden building lay to "
"the south.  A large stone wall stands to the north, "
"a strange symbol has been carved into a section of it.\n"
"\n"
"Northern Row continues to the east and west.\n");
add_exit("nr7","west");
add_exit("nr9","east");
add_exit("track_shop","south");

set_items(([
({"symbol","strange symbol","wall","stone wall","carving"}):
"A large symbol has been carved over a group of about "
"12 stone bricks...\n"
"  %^RED%^XXXXXX\n"
"  XX   XX\n"
" XXXX XX\n"
"  XX XX\n"
"    XX\n"
"\n"]));
}
void reset() {
::reset();
if(EVENTS_D->query_time_of_day()=="night"){
remove_item("symbol");
}
}
