#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Tunnel");
	set_long("The beautiful mushrooms that you just saw are no longer present, now there is only the harsh unwavering ground.  There are exits to the north and southeast, as well as the entrance from the west.");
	set_items(([
	"ground" : "The rock is ugly, yet beautiful in a random sense.",
	"rock" : "There are many different types of rock here."
	]));
	set_listen("default", "Only your cold hard footsteps can be heard.");
	set_smell("default", "You can only smell yourself.");
	set_exits( ({
	"/wizards/blial/under/rooms/s_6",
	"/wizards/blial/under/rooms/r_5",
	"/wizards/blial/under/rooms/t_4"
	}),({
	"north", "west", "southeast"
	}));
}


