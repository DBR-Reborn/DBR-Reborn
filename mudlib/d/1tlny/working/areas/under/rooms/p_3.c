#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Tunnel");
	set_long("After walking for a few minutes you notice that the path that you have chosen slants upwards into the darkness.  However after a few more minutes of walking you notice a dramatic change in the floor as the ground dips down in a 45 degree slant.");
	set_items(([
	"tunnel" : "The tunnel seems to go on forever.",
	"floor" : "The floor seems to slant up then slant down dramamtically.",
	]));
	set_listen("default", 
	"You can hear the sound of wind blowing through the tunnels."
	);
	set_smell("default",
	"It seems strange that you can't smell anything."
	);
	set_exits( ({
	"/wizards/blial/under/rooms/o_2",
	"/wizards/blial/under/rooms/p_4",
	}),({
	"southwest", "north"
	}));
}


