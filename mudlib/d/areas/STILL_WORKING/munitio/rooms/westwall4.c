//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The City Wall");
	set("long", "As you peer over the edge of the wall, you can see that the island's side becomes very sheer as it continues to the north. Combined with the steel barbs at the base of the wall the rest of the island is pretty much impregnable, so the walkway only continues on a short distance from this point. Just to the west is the break area for the guards.");
	add_exit(ROOMS+"westwall5", "west");
	add_exit(ROOMS+"westwall3", "southeast");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"wallguard.c")->move(this_object());
	new(MON+"wallguard.c")->move(this_object());
}
}
