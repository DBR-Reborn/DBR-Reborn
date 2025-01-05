#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Tunnels");
	set_long("You seem to be walking forever in the tunnels as they keep on splitting up again and again.  The tunnel splits up to the northeast and to the north, as well as the entrance from the south.");
	set_items(([
	"walls" : "The walls seem damp in this section of the tunnels.",
	"floor" : "The floor of the tunnel seems somewhat moist."
	]));
	set_listen("default", "You can hear the sloshing noise of your feet on the floor.");
	set_smell("default", "It smells like rotten vegetables in here.");
	set_exits( ({
	"/wizards/blial/under/rooms/q_5",
	"/wizards/blial/under/rooms/p_4",
	"/wizards/blial/under/rooms/r_5",
	}),({
	"north", "west", "northeast"
	}));
}


