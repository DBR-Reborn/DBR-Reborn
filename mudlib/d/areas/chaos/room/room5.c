#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "A fishermans house.");
	set("long", "This is a fishermans house, you can smell the rotten fish that was deposited here a few days ago.  This is a simple house, one built of wood and rocks.  The furniture is almost all destroyed, with bits of shattered wood splintered across the room.");
	set_property("light", 3);
	set_property("indoors", 2);
	set_exits( ({
	"road9.c",
}),
	({"south"}));
	set_smell("default", "The air is putrid, with the smell of dead fish.");
}
void reset(){
	::reset();
	if(!present("child")) {
	new(MON+"child.c")->move(this_object());
	new(OBJ+"fish.c")->move(this_object());
	new(OBJ+"fish.c")->move(this_object());
	new(MON+"child.c")->move(this_object());
    }
}
