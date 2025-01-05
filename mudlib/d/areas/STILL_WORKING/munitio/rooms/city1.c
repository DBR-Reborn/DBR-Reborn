//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Streets of Munitio");
	set("long", "The weary citizens of Munitio slog through ankle deep mud all around you. The buildings around you are actually quite small, far smaller than what you usually see in Daybreak Ridge. Most look quite dilapidated as well. To the west, a row of shops can be seen, and small houses are seen to the north. The gates rise high above you to the south.");
set_items( (["buildings": "They're made of brick, like normal ones. They're falling apart, though.",
"shops": "You shop in them.",
"houses": "Some people live in them. Not you - you live in the streets like the dog you are." ]) );
	add_exit(ROOMS+"gates", "south");
	add_exit(ROOMS+"city2", "west");
	add_exit(ROOMS+"city4", "north");
}

void reset() {
	::reset();
if(!present("guard")){
	new(MON+"cityguard.c")->move(this_object());
}

if(!present("citizen")){
	new(MON+"citizen.c")->move(this_object());
	new(MON+"citizen.c")->move(this_object());
	new(MON+"citizen.c")->move(this_object());
}
}
