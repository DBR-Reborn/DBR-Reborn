//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Streets of Munitio");
	set("long", "Munitio's forge district is a writhing mass of activity at all hours of the day. Hundreds of blacksmiths work endlessly at dozens of glowing forges. The noise is almost intolerable. Even when you stand a ways back, your ears still ring from the clanging of hammers against metal.");
set_items( (["blacksmiths": "They're all quite busy with their work.",
"forges": "You decide that they're glowing from heat, not magic, and that touching them would not be smart." ]) );
	add_exit(ROOMS+"city2", "south");
	add_exit(ROOMS+"city9", "north");
	add_exit(ROOMS+"city6", "west");
	add_exit(ROOMS+"city4", "east");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"cityguard.c")->move(this_object());
}

if(!present("citizen")){
	new(MON+"citizen.c")->move(this_object());
	new(MON+"citizen.c")->move(this_object());
	new(MON+"citizen.c")->move(this_object());
}
}
