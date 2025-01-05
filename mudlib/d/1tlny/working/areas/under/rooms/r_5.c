#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 2);
	set_short("Underground Tunnels");
	set_long("The section of the tunnel that you are now in seems to be filled with different kinds of small fungus, most of them seem to be rotting, but there are still some that are vibrant and beautiful.  The tunnel keeps going on to the northeast.");
	set_items(([
	"fungus" : "These fungi seem to fill up the whole room, even where you stand.  Some of them are beautiful as the light the room up with their incandescent glow.",
	]));
	set_listen("default", "The only sound that you hear is the mellow sound of your feet on the fungi.");
	set_smell("default", "Even though there are many beautiful fungi here, the overbearing smell of decaying fungi invade your nostrils.");
	set_exits( ({
	"/wizards/blial/under/rooms/s_5",
	"/wizards/blial/under/rooms/q_4"
	}),({
	"east", "southwest"
	}));
}


