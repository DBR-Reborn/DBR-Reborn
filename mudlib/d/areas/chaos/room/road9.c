#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "Corner of Livingstone and Rockfish road.");
	set("long", "This is the Corner of Livingstone and Rockfish road, burnt houses rage strongly here, even though the beach is near.  The room here is unnaturally bright, with glitter splattered all along the floor.");
	set_property("light", 3);
	set_smell("default", "The smell here is very strange, almost entrancing.");
	set_listen("default", "This room sounds so beautiful, it almost hurts your ears to hear it.");
	set_property("indoors", 2);
	set_property("light", 3);
	set_exits( ({
	"room5.c",
	"room4.c",
	"road8.c",
	"road10.c"}),
	({"north", "east", "south", "west"}));
}

void reset() {
	::reset();
	if(!present("champion")) {
	new(MON+"slaneeshc.c")->move(this_object());
	new(MON+"swarrior.c")->move(this_object());
	new(MON+"swarrior.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
    }
}
