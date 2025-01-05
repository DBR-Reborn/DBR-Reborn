#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Tunnels");
	set_long("The tunnel ends in a small cavern, about 10 feet by 10 feet.  There are 3 small holes to the north that you think you might be able to fit in, as well as the small hole that is to the south.");
	set_items(([
	"walls" : "The walls seem damp in this section of the tunnels.",
	"floor" : "The floor of the tunnel seems somewhat moist."
	]));
	set_listen("default", "You can hear the sloshing noise of your feet on the floor.");
	set_smell("default", "It smells like sweat soaked leather.");
	set_exits( ({
	"/wizards/blial/under/rooms/o_10",
	"/wizards/blial/under/rooms/p_10",
	"/wizards/blial/under/rooms/o_8",
	"/wizards/blial/under/rooms/n_10",
	}),({
	"north", "northeast", "south", "northwest"
	}));
}


