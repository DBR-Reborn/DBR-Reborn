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
	"uw_10.c"}),
	({"east"}));
}
void reset() {
	::reset();
	if(!present("undead dragon")) {
	new(MON+"un_dragon.c")->move(this_object());
	//new(MON+"dp.c")->move(this_object());

    }
}
