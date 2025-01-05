//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Streets of Munitio");
	set("long", "The houses here can barely be called houses. Most of them are in the process of falling in on themselves, and several are only being supported by the building next to them. Still, all of them appear to be inhabited. There is a definite smell to this part of town, and it isn't good.");
set_items( (["smell": "You don't look at a smell, genius.",
"houses": "Needless to say, you feel really sorry for anyone who lives in these pieces of trash." ]) );
	add_exit(ROOMS+"city14", "north");
	add_exit(ROOMS+"city11", "west");
	add_exit(ROOMS+"city9", "east");
	add_exit(ROOMS+"city6", "south");
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
