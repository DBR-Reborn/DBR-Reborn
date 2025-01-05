//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The City Wall");
	set("long", "This section of the wall overlooks the blacksmiths' housing quarter. The guards here seem to be watching the ground below more than the outside world, and there are quite a few guards on the ground as well. Could it be that they fear rebellion more than invasion?");
set_items( (["guards": "Since you didn't really see that many pretty girls down below, you don't know what they're looking at." ]) );
	add_exit(ROOMS+"eastwall3", "south");
	add_exit(ROOMS+"eastwall5", "north");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"wallguard.c")->move(this_object());
	new(MON+"wallguard.c")->move(this_object());
	new(MON+"wallguard.c")->move(this_object());
}
}
