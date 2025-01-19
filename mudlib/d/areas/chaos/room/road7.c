#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "The intersection of Livingstone and Pebble Street");
	set("long", "This is the intersection of Livingstone and Pebble Street, Pebble street is the road where the abundance of people live in Kislev.  Although you doubt that there are many people living there now.  The houses on the corners or Livingstone and Pebble are all on fire right now, with people scurrying throughout the houses.");
	set_property("indoors", 2);
	set_property("light", 3);
	set_smell("default", "You smell the general sent of death");
	set_listen("default", "Screams are heard all the way through Pebble street");
	set_exits( ({
	"road8.c",
	"road24.c",
	"road6.c",
	"room3.c"}),
	({"north", "east", "south", "west"}));
}
void reset() {
	::reset();
	if(!present("peasant")) {
	new(MON+"peasant.c")->move(this_object());
	new(MON+"peasant.c")->move(this_object());
	new(MON+"peasant.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
    }
}
