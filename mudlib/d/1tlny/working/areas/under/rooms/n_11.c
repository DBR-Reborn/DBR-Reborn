#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Tunnels");
	set_long("You can feel yourself becoming a little paranoid, as the tunnels are extremely small.  The rocks around you scrap your arms and legs as you squeeze through them.");
	set_items(([
	"walls" : "The walls seem damp in this section of the tunnels.",
	"floor" : "The floor of the tunnel seems somewhat moist."
	]));
	set_listen("default", "You can hear your skin scrap against the walls.");
	set_smell("default", "It smells like sweat soaked leather.");
	set_exits( ({
	"/wizards/blial/under/rooms/n_10",
	"/wizards/blial/under/rooms/m_12",
	}),({
	"south", "northwest"
	}));
}


