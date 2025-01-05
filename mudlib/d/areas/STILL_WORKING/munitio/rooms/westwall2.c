//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The City Wall");
	set("long", "The wall here overlooks several shops on one side and gives a pleasant view of the ocean on the other. The hustle and bustle of the town is almost amazing. The wall continues southeast and west.");

	add_exit(ROOMS+"westwall1", "southeast");
	add_exit(ROOMS+"westwall3", "west");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"wallguard.c")->move(this_object());
	new(MON+"wallguard.c")->move(this_object());
}
}
