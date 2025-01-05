#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "A room without a view.");
	set("long", "This house has nothing in it, no furniture, no plants, nothing.  Except for the few dead bodies that lie around the place.");
	set_property("light", 3);
	set_smell("default", "The stench of decaying bodies is great here.");
	set_property("indoors", 2);
	set_exits( ({
	"road15.c",
}),
	({"south"}));
}
void reset(){
	::reset();
	if(!present("body")) {
	new(OBJ+"body.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
    }
}
