//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Streets of Munitio");
	set("long", "This is Munitio's housing district. This area can only be called a slum, with ramshackle houses smashed together row after row. This is where the blacksmiths in the city live, and you begin to wonder if they're even here by their own will. As poor as these people are, they appear generally happy and well fed.");
set_items( (["houses": "The roofs are falling in, the walls are collapsing, and poor families must live in them. You feel like killing the man in charge, who is brutally opressing everyone."]) );
	add_exit(ROOMS+"city12", "north");
	add_exit(ROOMS+"city9", "west");
	add_exit(ROOMS+"city4", "south");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"cityguard.c")->move(this_object());
	new(MON+"cityguard.c")->move(this_object());
}

if(!present("citizen")){
	new(MON+"citizen.c")->move(this_object());
	new(MON+"citizen.c")->move(this_object());
	new(MON+"citizen.c")->move(this_object());
	new(MON+"citizen.c")->move(this_object());
	new(MON+"citizen.c")->move(this_object());
}
}
