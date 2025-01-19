#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "The intersection between Rockfish and Market Street.");
	set("long", "This is the intersection between Rockfish and Market Street, everything is in the state of decay, building no longer burn with fire, only rot with feotid disease.");
	set_smell("default", "It smells like the latrine of a dead janitor.");
	set_property("light", 3);
	set_listen("default", "There is laughter in the air.");
	set_property("indoors", 2);
	set_exits( ({
	"room7.c",
	"road14.c",
	"road16.c",
	"room8.c"}),
	({"north", "east", "south", "west"}));
}
void reset() {
	::reset();
	if(!present("champion")) {
	new(MON+"nurglec.c")->move(this_object());
	new(MON+"nwarrior.c")->move(this_object());
	new(MON+"nwarrior.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
    }
}
