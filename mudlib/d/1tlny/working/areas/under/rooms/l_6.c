#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Tunnel");
	set_long("After walking for a while among the perculiar boulders, their numbers seem to decrease drastically, until there are only about two or three left.  However, the floor is now covered with small fragments of rock.");
	set_items(([
	"boulder" : "These boulders are polished to a shine.",
	"fragments" : "These fragments of the boulders, seem to be cut roughly.",
	]));
	set_listen("default", "You can slightly hear the sounds of rumbling.");
	set_smell("default", "The air smells rusty.");
	set_exits( ({
	"/wizards/blial/under/rooms/l_7.c",
	"/wizards/blial/under/rooms/m_5.c",
	}),({
	"north", "southeast",
	}));
}


