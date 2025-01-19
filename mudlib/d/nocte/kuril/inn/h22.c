// Hallway of the Wretched Zombie Inn

#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("light", 2);
	set_short("Hallway of the Wretched Zombie Inn");
	set_long(
		"You are in a hallway of the Wretched Zombie Inn"
	);

    add_exit("/d/nocte/kuril/inn/h32", "north");
    add_exit("/d/nocte/kuril/inn/h12", "south");

}
