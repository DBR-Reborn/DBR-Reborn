#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Tunnel");
	set_long("The vast underground tunnels that you have been traveling for unknown amounts of time comes to an abrupt stop as it splits into a fork going northwest and northeast.");
	set_items(([
	"floor" : "The floor seems to slant down from here a little bit.",
	"tunnel" : "The tunnel splits up into 2 exits.",
	]));
	set_listen("default", 
	"You can hear your footsteps reverberating off the walls of the tunnel."
	);
	set_smell("default",
	"The smell of stagnant air permeats your nose."
	);
	set_exits( ({
	"/wizards/blial/under/rooms/o_1",
	"/wizards/blial/under/rooms/n_3",
	"/wizards/blial/under/rooms/p_3",
	}),({
	"south", "northwest", "northeast",
	}));
}


