//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The City Wall");
	set("long", "A couple of guards are hanging out here in the break area, smoking and eating something from their lunches. While you're not sure the food will hurt them (as it looks disgusting), the smoking is sure to do some damage to them. You silently cheer.");
set_items( (["break area": "It's composed of a table and some chairs.",
"smokers": "Smoking is bad.",
"eaters": "It's a much safer past-time than smoking.",
"guards": "Guards guard things." ]) );
	add_exit(ROOMS+"westwall4", "east");
}

void reset() {
	::reset();
if(!present("guard")){
	new(MON+"wallguard.c")->move(this_object());
	new(MON+"wallguard.c")->move(this_object());
	new(MON+"wallguard.c")->move(this_object());
}
}
