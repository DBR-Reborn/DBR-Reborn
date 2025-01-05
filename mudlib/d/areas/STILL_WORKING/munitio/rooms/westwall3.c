//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The City Wall");
	set("long", "The wall here bends to the northwest for a bit before terminating in a small break area for the guards on duty. The guards mostly pass the time by playing cards. You doubt you'd be welcome in a game.");
set_items( (["guards": "They make crude jokes as they carouse and play cards.",
"cards": "Just as well that they won't let you play - you're not good at Three Skull Gambit." ]) );
	add_exit(ROOMS+"westwall4", "northwest");
	add_exit(ROOMS+"westwall2", "east");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"wallguard.c")->move(this_object());
	new(MON+"wallguard.c")->move(this_object());
}
}
