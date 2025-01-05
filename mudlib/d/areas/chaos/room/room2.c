#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "A small house");
	set("long", "This is a small house where all the furniture has been destroyed by the maruading bands of chaos.  Bits and pieces sit idly everywhere in the room. There are some people hiding in here.");
	set_property("indoors", 2);
	set_exits( ({
	"road5.c",
}),
	({"west"}));
	set_smell("default", "The air is permeated by soot and the smell of charcoal.");
}
void reset(){
::reset();
	if(!present("peasant")) {
	new(MON+"peasant.c")->move(this_object());
	new(MON+"peasant.c")->move(this_object());
    }
}
