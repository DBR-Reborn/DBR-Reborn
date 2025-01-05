#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Tunnels");
	set_long("These are underground tunnels, they seem to go on for an eternity in multiple directions yet even with all the difference they are still completely monotonous.");
	set_items(([
	"walls" : "The walls seem damp in this section of the tunnels.",
	"floor" : "The floor of the tunnel seems somewhat moist."
	]));
	set_listen("default", "You can hear the sloshing noise of your feet on the floor.");
	set_smell("default", "It smells like sweat soaked leather.");
	set_exits( ({
	"/wizards/blial/under/rooms/q_4",
	"/wizards/blial/under/rooms/p_6",
	}),({
	"south", "northwest"
	}));
}


