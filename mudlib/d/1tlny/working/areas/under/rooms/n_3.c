#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Tunnel");
	set_long("As you walk through this section of the underground tunnel, you can feel that the ground slopes down from here.  After a little bit of walking the sloping stops and ends in a flat platform that exits to the north.");
	set_items(([
	"slope" : "The slope is very slight, only about 5 degrees.",
	"platform" : "The platform ends the slanted entrance of this section of the tunnel."
	]));
	set_listen("default", 
	"The sounds seem to fade away as you keep on walking."
	);
	set_smell("default",
	"The air is damp with stagnant water."
	);
	set_exits( ({
	"/wizards/blial/under/rooms/o_2",
	"/wizards/blial/under/rooms/n_4",
	}),({
	"southeast", "north",
	}));
}


