#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "Upstairs bedroom.");
	set("long", "An upstairs bedroom to a house in Kislev, there seems to be a spattering of blood all along the walls, while the bed seems somewhat untouched.  There isn't much else except for the bed in this room, everything else was destroyed.");
	set_listen("default", "You can hear a child crying here.");
	set_property("indoors", 2);
	set_exits( ({
	"room1.c",
}),
	({"down"}));
	set_smell("default", "The air is fresh.");
}
void reset(){
	::reset();
	if(!present("child")) {
	new(MON+"child.c")->move(this_object());
	new(MON+"child.c")->move(this_object());
    }
}
