//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "A serene garden");
	set("long", "This small garden is one of the most beautiful things you have ever seen. Exotic plants cover every inch of available space, and on the far wall a small waterfall has been built, which spills into a pool full of radiant fish.");
set_items( (["plants": "You're not exactly sure what kinds they are, but they _look_ exotic!",
"waterfall": "Falling water. It looks clear.",
"pool": "Fish are swimming in it.",
"fish": "You try to grab one to eat it, but it swims away." ]) );
	add_exit(ROOMS+"house", "house");
}


void reset() {
	::reset();
if(!present("governor")){
	new(MON+"governor.c")->move(this_object());
}
}
