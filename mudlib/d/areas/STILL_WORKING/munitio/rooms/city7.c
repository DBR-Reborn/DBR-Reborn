//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Streets of Munitio");
	set("long", "This is the western edge of the forge district. The Munitio Public Forge is here at the western end of the street. That is where blacksmiths can all use the equally same forge area. You wonder if Munitio is really Communist, but dismiss the idea.");
	add_exit(ROOMS+"forge", "forge");
	add_exit(ROOMS+"city11", "north");
	add_exit(ROOMS+"city6", "east");
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
