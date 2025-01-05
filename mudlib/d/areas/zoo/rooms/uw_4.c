#include <std.h>
#include "../zoo.h"

inherit ROOM;

void create() {
	::create();
	set_short("Underworld of DayBreak");
	set_long("The Underworld. Here you will find nothing but death and decay.");
	set_property("light", 3);
	set_property("indoors", 2);
	set_smell("default", "It smells like decaying corpses.");
	set_listen("default", "You hear the screams of the damned.");
	set_exits( ({
	"uw_3.c",
	"uw_4-1.c",
	"uw_8.c",
	"uw_9.c",}),
	({"up", "down", "east","west"}));
}
void reset() {
	::reset();
	if(!present("demon prince")) {
	new(MON+"dp.c")->move(this_object());
	new(MON+"dp.c")->move(this_object());
	new(MON+"dp.c")->move(this_object());
	new(MON+"dp.c")->move(this_object());

    }
}
