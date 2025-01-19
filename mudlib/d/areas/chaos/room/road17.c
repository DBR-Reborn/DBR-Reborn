#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("long", "This is Market Street, there used to be many stores here, but now most of them are in a state of destruction.  You can see the remanants of an inn to your east and a shop to your west.");
	set_listen("default", "You can hear some shuffling coming from your east and west.");
	set("short", "Along Market Street.");
	set_property("light", 3);
	set_property("indoors", 2);
	set_exits( ({
	"road16.c",
	"room9.c",
	"road18.c",
	"pyre_shop.c"}),
	({"north", "east", "south", "west"}));
}
void reset() {
	::reset();
	if(!present("beastman")) {
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(MON+"peasant.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
    }
}
