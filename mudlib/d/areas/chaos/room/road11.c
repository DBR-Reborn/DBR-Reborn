#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "Rockfish Road, near the pier.");
	set("long", "This is Rockfish Road, usually populated by many people, now deserted. Dead birds spatter the floor with an artistic redness to it.");
	set_smell("default", "You can faintly smell perfume here.");
	set_property("light", 3);
	set_listen("default", "You can only hear the sound of wood crakling in the distance.");
	set_property("indoors", 2);
	set_exits( ({
	"road10.c",
	"road12.c"}),
	({"east", "west"}));
}
void reset() {
	::reset();
    	if(!present("peasant")) {
	new(MON+"peasant.c")->move(this_object());
	new(MON+"peasant.c")->move(this_object());
	new(MON+"peasant.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
    }
}
