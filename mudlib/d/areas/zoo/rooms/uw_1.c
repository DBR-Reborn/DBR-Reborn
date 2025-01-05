#include <std.h>
#include "../zoo.h"

inherit ROOM;

void create() {
	::create();
	set_short("Underworld Entrance");
	set_long("This is the entrance to the Underworld. Here you will find nothing but death and decay. Travelers beware.");
	set_property("light", 3);
	set_property("indoors", 2);
	set_smell("default", "It smells like decaying corpses.");
	set_listen("default", "You hear ... silence.");
	set_exits( ({
	"main.c",
	"uw_2.c"}),
	({"up", "down"}));
}
void reset() {
	::reset();
	if(!present("demon lord")) {
	new(MON+"dlord.c")->move(this_object());
	new(MON+"dlord.c")->move(this_object());
	new(MON+"dlord.c")->move(this_object());
	new(MON+"dlord.c")->move(this_object());

    }
}
