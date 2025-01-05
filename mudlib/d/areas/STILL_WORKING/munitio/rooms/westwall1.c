//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The City Wall");
	set("long", "The guards here are rather pushy as they patrol back and forth and aren't terribly careful about not knocking you off the wall, so you have to take great caution not to plunge 20 feet on to the muddy road below. You barely resist the urge to shove one of _them_ off.");
set_items( (["guards": "You look at one of the guards.\n Soon, he gets annoyed, and rushes you!\n You deftly trip him!\nGuard falls over the tower to his doom! Yay!\n",
"road": "It's usually made of dirt, but now it's made of mud. Wait, dirt is mud. Never mind.",
"wall": "Try to stay on top of it for maximum benefit." ]) );
	add_exit(ROOMS+"gates", "east");
	add_exit(ROOMS+"westwall2", "northwest");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"wallguard.c")->move(this_object());
	new(MON+"wallguard.c")->move(this_object());
}
}
