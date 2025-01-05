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
	"uw_2.c",
	"uw_4.c",
	"uw_5.c",
	"uw_6.c",}),
	({"up", "down", "east","west"}));
}
void reset() {
	::reset();
	if(!present("zombie spirit")) {
	new(MON+"zspirit.c")->move(this_object());
	new(MON+"bloodfiend.c")->move(this_object());
	new(MON+"sessence.c")->move(this_object());
	new(MON+"vhound.c")->move(this_object());

    }
}
