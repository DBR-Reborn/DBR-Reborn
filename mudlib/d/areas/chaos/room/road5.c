#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "The corner of east road and livingstone street");
	set("long", "This is the corner of east road and livingstone street. There is a house to the south, which isn't destroy as yet, and there is a beaten up shop to the east.  Fire burns strong along livingstone street, you can hear screams of fear and horror.");
	set_property("indoors", 2);
	set_property("light", 3);
	set_smell("default", "It smells burnt skin");
	set_listen("default", "Screams are heard along livingstone and east road.");
	set_exits( ({
	"road6.c",
	"room2.c",
	"room1.c",
	"road4.c"}),
	({"north", "east", "south", "west"}));
}
void reset() {
	::reset();
	if(!present("champion")) {
	new(MON+"khornec.c")->move(this_object());
	new(MON+"peasant.c")->move(this_object());
	new(MON+"peasant.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
    }
}
