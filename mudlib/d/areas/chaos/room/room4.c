#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "A house with a view.");
	set("long", "This is one of the most beautiful houses you have ever seen before, with a view of the ocean that is truely breath taking.  Too bad the building is charred and burned by the fires of chaos. Almost all of the furniture is burnt beyond recognition. A few bodies are deposited around the room, like pillows of death.");
	set_property("light", 3);
	set_property("indoors", 2);
	set_exits( ({
	"road9.c",
}),
	({"west"}));
	set_smell("default", "The air is permeated by soot and the smell of charcoal.");
}
void reset(){
	::reset();
	if(!present("body")) {
	new(OBJ+"body.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
	new(MON+"dog.c")->move(this_object());
    }
}
