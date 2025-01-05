#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Tunnel");
	set_long("The ground is covered with small fragments of rock, while the large boulders that you have seen before are no longer present.");
	set_items(([
	"fragments" : "These fragments of the boulders, seem to be cut roughly.",
	"ground" : "The ground is covered with fragments.",
	]));
	set_listen("default", "You can slightly hear the sounds of rumbling.");
	set_smell("default", "The air smells rusty.");
	set_exits( ({
	"/wizards/blial/under/rooms/l_6.c",
	"/wizards/blial/under/rooms/k_8.c",
	}),({
	"south", "northwest",
	}));
}


