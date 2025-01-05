#include <std.h>
#include "../zoo.h"

inherit ROOM;

void create() {
	::create();
	set_short("Entrance to the Zoo");
	set_long("This is the lobby of the DayBreak Zoo. Here you will find the many pets that exist in the realm.\n\n"
				"The Zookeeper welcomes you... \n\n"
				"West is the Dragon and Elemental Keep.\n"
				"Down is the Underworld.\n");
	set_property("light", 3);
	set_property("indoors", 2);
	set_smell("default", "It smells like a zoo...");
	set_listen("default", "You hear a symphony of various animale sounds.");
	set_exits( ({
	"/d/damned/virtual/room_8_56.world",
	"dk_1.c",
	"uw_1.c"}),
	({"out", "west", "down"}));
}
void reset() {
	::reset();
	if(!present("sasa")) {
	new(MON+"sasa.c")->move(this_object());
	//new(MON+"dp.c")->move(this_object());

    }
}
