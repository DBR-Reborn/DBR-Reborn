#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "Near the Crossroads.");
	set_long("This is the part of the West road that connects with the Crossroads.  All the houses here seem to be the most badly damaged, as you suspect the incursions of Chaos happened here first.  You don't see anything much except for a few peasants roaming around.");
	set_listen("default", "There is crying in the distance.");
	set_property("light", 3);
	set_property("indoors", 2);
	set_exits( ({
	"xroads.c",
	"road22.c",
}),
	({"east", "west"}));
}
void reset(){
	::reset();
	if(!present("peasant")) {
	new(MON+"peasant.c")->move(this_object());
	new(MON+"peasant.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
    }
}
