#include <std.h>
#include "../zoo.h"

inherit ROOM;

void create() {
	::create();
	set_short("Entrance to the Elemental Keep");
	set_long("This is the entrance to the Elemental Keep. \n"
			 "Here you will find various creatures created by the elements.\n\n");
	set_property("light", 3);
	set_property("indoors", 2);
	set_smell("default", "It smells surprisingly fresh.");
	set_listen("default", "You hear loud screeches.");
	set_exits( ({
	"dk_1-1.c"}),
	({"north"}));
}
void reset() {
	::reset();
	if(!present("elemental warrior")) {
	new(MON+"ele_warrior.c")->move(this_object());
	new(MON+"ele_warrior.c")->move(this_object());
	new(MON+"ele_warrior.c")->move(this_object());
	new(MON+"ele_warrior.c")->move(this_object());
    }
}
