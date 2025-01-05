//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The City Wall");
	set("long", "This is the last real segment of wall, a small section sticks off to the northwest which appears to be a sort of break area, as there are a few guards there smoking and sitting around. The guards' barracks are neatly arranged on the ground below you.");
set_items( (["barracks": "You see tiny little guards scurry in and out." ]) );
	add_exit(ROOMS+"eastwall4", "south");
	add_exit(ROOMS+"eastwall6", "northwest");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"wallguard.c")->move(this_object());
	new(MON+"wallguard.c")->move(this_object());
}
}
