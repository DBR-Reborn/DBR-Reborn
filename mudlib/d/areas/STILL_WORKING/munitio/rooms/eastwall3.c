//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The City Wall");
	set("long", "This section of wall runs in a straight line almost all the way to the edge of this part of the island. To the left and below you is the eastern edge of the forge district. Even from up here, you can hear the sounds of blacksmiths doing their jobs.");
set_items( (["walls": "They keep things out - and also keep things in." ]) );
	add_exit(ROOMS+"eastwall4", "north");
	add_exit(ROOMS+"eastwall2", "southwest");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"wallguard.c")->move(this_object());
	new(MON+"wallguard.c")->move(this_object());
}
}
