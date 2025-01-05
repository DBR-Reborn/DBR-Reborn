#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Tunnels");
	set_long("The passage that was so tight to your body, now extends comfortable for your mind and body.  The tunnel seems to grow connically outward towards a large cavern.");
	set_items(([
	"walls" : "The walls seem damp in this section of the tunnels.",
	"floor" : "The floor of the tunnel seems somewhat moist."
	]));
	set_listen("default", "You can hear your feet on the dry rock.");
	set_smell("default", "It smells like sweat soaked leather.");
	set_exits( ({
	"/wizards/blial/under/rooms/m_12",
	"/wizards/blial/under/rooms/l_11",
	}),({
	"east", "south"
	}));
}


