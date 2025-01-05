#include <std.h>
#include "../test_area.h"

inherit ROOM;

void create() {
	::create();
	set_short("Honspron's Area");
	set_long("This is a test");
	set_property("light", 3);
	set_property("indoors", 2);
	set_smell("default", "Stinky Farts.");
	set_listen("default", "You hear ... gas?.");
	set_exits( ({
	"room_1.c"}),
	({"east"}));
}
void reset() {
	::reset();
	if(!present("pet 3")) {
	new(MON+"mon_3.c")->move(this_object());
	new(MON+"mon_3.c")->move(this_object());
	new(MON+"mon_3.c")->move(this_object());
	new(MON+"mon_3.c")->move(this_object());

    }
}
