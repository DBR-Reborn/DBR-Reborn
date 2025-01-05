#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Tunnel");
	set_long("The underground tunnel that you have been wandering around in now seems to split up into a fork to the east and to the northwest.
	");
	set_items(([
	"tunnel" : "The tunnels seem to go on forever.",
	]));
	set_listen("default", 
	"You can't hear anything, except for your own footsteps."
	);
	set_smell("default",
	"You can smell the foul odor of decay in the air."
	);
	set_exits( ({
	"/wizards/blial/under/rooms/p_3",
	"/wizards/blial/under/rooms/q_4",
	"/wizards/blial/under/rooms/n_5",
	}),({
	"south", "east", "northwest",
	}));
}


