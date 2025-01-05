#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Tunnel");
	set_long("This section of underground tunnel is characterized by large polished boulders that sit idly amongst themselves in a ring of thought.");
	set_items(([
	"boulder" : "These boulders are polished to a shine.",
	"ring" : "It is strange that these boulders are arranged this way.",
	]));
	set_listen("default", "You can slightly hear the sounds of rumbling.");
	set_smell("default", "The air smells rusty.");
	set_exits( ({
	"/wizards/blial/under/rooms/m_4.c",
	"/wizards/blial/under/rooms/l_5.c",
	"/wizards/blial/under/rooms/l_6.c",
	}),({
	"south", "west", "northwest"
	}));
}


