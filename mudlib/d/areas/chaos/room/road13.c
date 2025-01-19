#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "West side of Rockfish Road.");
	set("long", "This is the west side of Rockfish Road, there are still many buildings here burning, with the local townsfolk, crying and caring for the recently deceased.");
	set_smell("default", "You can smell the putrid musk of decay coming from the west.");
	set_property("light", 3);
	set_listen("default", "Everything seems quiet, except for the maniacal laughter from the west.");
	set_property("indoors", 2);
	set_exits( ({
	"house2.c",
	"road12.c",
	"road14.c"}),
	({"north", "east", "west"}));
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
