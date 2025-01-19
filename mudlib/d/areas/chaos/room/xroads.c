#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "A crossroad of streets");
	set_long("This is the town square, there used to be a statue of the great Ice Queen of Kislev standing here, now it is in pieces.  The buildings around you are on fire or are destroy.  To the north you can seen the palace of Kislev, a wonderful structure, unsurpassed in its beauty and elegance, except that the sound of violence and bloodshed drown out the serenity of the sight.");
	set_property("indoors", 2);
	set_property("light", 3);
	set_items( ([ "statue": "This was once a beautiful statue of the Ice Queen of Kislev, now in pieces.",
]));
	set_exits( ({
	"road1.c",
	"road23.c",
	"kislevent.c",
	"road3.c"}),
	({"north", "west", "south", "east"}));
}

void reset() {
	::reset();
	if(!present("beastman")) {
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
    }
}
