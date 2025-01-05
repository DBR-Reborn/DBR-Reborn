//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Streets of Munitio");
	set("long", "This area appears to be reserved for the families of the city guards. More guards are milling around here, but they appear to be mostly on duty. You wonder why there is a such large number of guards, until you realize that the blacksmiths and their families probably wish these people quite a bit of ill will...");
set_items( (["families": "They really aren't any better off than the families of the blacksmiths.",
"blacksmiths": "They don't like the guards. At all.",
"guards": "You occasionaly see one club a blacksmith." ]) );
	add_exit(ROOMS+"city13", "east");
	add_exit(ROOMS+"city10", "south");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"cityguard.c")->move(this_object());
	new(MON+"cityguard.c")->move(this_object());
	new(MON+"gateguard.c")->move(this_object());
	new(MON+"gateguard.c")->move(this_object());
	new(MON+"cityguard.c")->move(this_object());
	new(MON+"gateguard.c")->move(this_object());
}
}
