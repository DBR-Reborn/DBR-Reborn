#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "A house covered in blood.");
	set("long", "This house is covered in blood of the innocent people that lived here.  The furniture has all been destroyed by the warriors of Chaos, the tables, chairs, everything.  There are a few assorted body parts laying around the room.  You see a set of stairs leading up to the bedroom.");
	set_property("indoors", 2);
	set_exits( ({
	"road5.c",
	"room1-2.c",
}),
	({"north", "up"}));
	set_smell("default", "The air is damp and musky.");
	set_listen("default", "You can hear some whimpering in the bedroom.");
}
void reset(){
	::reset();
	if(!present("body")) {
	new(OBJ+"body.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
    }
}
