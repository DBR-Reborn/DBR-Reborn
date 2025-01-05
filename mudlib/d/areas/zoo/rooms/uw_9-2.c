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
	"uw_9.c"}),
	({"north"}));
}
void reset() {
	::reset();
	if(!present("soul knight")) {
	new(MON+"soulknight.c")->move(this_object());
	new(MON+"soulknight.c")->move(this_object());
	new(MON+"soulknight.c")->move(this_object());
	new(MON+"soulknight.c")->move(this_object());

    }
}
