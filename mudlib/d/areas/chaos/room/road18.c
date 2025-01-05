#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "South side of Market Street.");
	set("long", "This is the south side of Market Street, the buildings are still burning here but not with the usual orange-flames, but with chaotic flames of green and blue.");
	set_smell("default", "You can smell something but it keeps changing.");
	set_property("light", 3);
	set_property("indoors", 2);
	set_exits( ({
	"road17.c",
	"road19.c",
	"room11.c"}),
	({"north", "south", "west"}));
}
void reset() {
	::reset();
	if(!present("warrior")) {
	new(MON+"twarrior.c")->move(this_object());
	new(MON+"phorror.c")->move(this_object());
	new(MON+"twarrior.c")->move(this_object());
	new(MON+"twarrior.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
    }
}
