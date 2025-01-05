//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The City Wall");
	set("long", "The wall surrounding the city affords a nice view of the surrounding area, but you have to pay attention to your more immediate surroundings as guards wander back and forth giving you strange looks.");
set_items( (["surroundings": "Just a lot of water. But nice water!",
"guards": "They're suspicious of you - but for what?" ]) );
	add_exit(ROOMS+"eastwall2", "east");
	add_exit(ROOMS+"gates", "west");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"wallguard.c")->move(this_object());
	new(MON+"wallguard.c")->move(this_object());
}
}
