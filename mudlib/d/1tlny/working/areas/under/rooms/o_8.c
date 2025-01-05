#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Tunnels");
	set_long("The tunnel starts to become smaller until it can only fit one person, you can feel the cold hard stone rubbing against your skin.");
	set_items(([
	"walls" : "The walls seem damp in this section of the tunnels.",
	"floor" : "The floor of the tunnel seems somewhat moist."
	]));
	set_listen("default", "You can hear the sloshing noise of your feet on the floor.");
	set_smell("default", "It smells like sweat soaked leather.");
	set_exits( ({
	"/wizards/blial/under/rooms/p_7",
	"/wizards/blial/under/rooms/o_9",
	}),({
	"southeast", "north"
	}));
}


