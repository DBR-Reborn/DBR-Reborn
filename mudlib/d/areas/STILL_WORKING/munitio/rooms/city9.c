//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Streets of Munitio");
	set("long", "The further you get from the main road the more squalid the houses become. Several of the houses here are one-room affairs, several appear to have rather large families crammed inside. Several houses apparently have collapsed, and you wonder if their occupants made it out in time.");
set_items( (["houses": "You cry just looking at them.",
"families": "You'd think these people would have less kids with living conditions like these." ]) );
	add_exit(ROOMS+"city13", "north");
	add_exit(ROOMS+"city10", "west");
	add_exit(ROOMS+"city8", "east");
	add_exit(ROOMS+"city5", "south");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"cityguard.c")->move(this_object());
	new(MON+"cityguard.c")->move(this_object());
}

if(!present("citizen")){
	new(MON+"citizen.c")->move(this_object());
	new(MON+"citizen.c")->move(this_object());
	new(MON+"citizen.c")->move(this_object());
	new(MON+"citizen.c")->move(this_object());
	new(MON+"citizen.c")->move(this_object());
}
}
