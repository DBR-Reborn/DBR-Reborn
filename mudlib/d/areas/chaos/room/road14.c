#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "West side of Rockfish Road.");
	set("long", "This is the West side of Rockfish Road, you can see the wood still burning lively among the buildings.  Here and there you see dead rats, decayed and foaming around the mouth, they litter the street like a disgusting layer of carpet.");
	set_property("indoors", 2);
	set_property("light", 3);
	set_exits( ({
	"room6.c",
	"road13.c",
	"road15.c"}),
	({"north", "east", "west"}));
}
void reset() {
	::reset();
	if(!present("warrior")) {
	new(MON+"nwarrior.c")->move(this_object());
	new(MON+"nwarrior.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
	new(MON+"peasant.c")->move(this_object());
    }
}
