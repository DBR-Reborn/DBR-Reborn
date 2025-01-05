//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The City Wall");
	set("long", "This is sort of a break area for the guards on the wall. Several guards are sitting around smoking and talking. You smile, knowing that the smoke will foul all of their lungs, and eventually kill them. That would be a very good thing.");
set_items( (["smokers": "Smoking is bad.",
"guards": "You see a pair making out in the corner of the area. Hmm." ]) );
	add_exit(ROOMS+"eastwall5", "southeast");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"wallguard.c")->move(this_object());
	new(MON+"wallguard.c")->move(this_object());
	new(MON+"wallguard.c")->move(this_object());
}
}
