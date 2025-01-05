//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	set_pre_exit_functions( ({"house"}), ({"blocker"}) );
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Streets of Munitio");
	set("long", "This is the courtyard for the largish house at the far northern end of the island. The house isn't as large as you first thought, clever landscaping and design give the illusion of size. The entire house appears to be nothing but one large room. Through the windows you can see an orange glow - apparently there is a forge inside here as well. ");
set_items( (["house": "Big and beautiful. You can only guess as to why it's only one room, though.",
"forge": "Well, it _sounds_ like a forge." ]) );
	add_exit(ROOMS+"city16", "south");
	add_exit(ROOMS+"house", "house");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"ucguard.c")->move(this_object());
	new(MON+"ucguard.c")->move(this_object());
}
if(!present("aristocracy")){
	new(MON+"aristocracy.c")->move(this_object());
	new(MON+"aristocracy.c")->move(this_object());
}
}

int blocker() {
	if(present("guard")) {
	write("The guard cracks you extremely hard across the face, sending you sprawling in the dirt.");
	return 0;
	}
	else
	return 1;
}
