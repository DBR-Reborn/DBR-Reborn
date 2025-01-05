//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Streets of Munitio");
	set("long", "This is the western end of the shop area. A pair of run down taverns form the far western edge of the area, but they appear to be closed at the moment. You bet that it's because the cruel, oppressive governor didn't want these people to be happy and drunk, since it would affect their work efficiency.");
set_items( (["taverns": "You'll never understand how a tavern named 'The Howling Harlot' could ever be closed down."]) );
	add_exit(ROOMS+"city6", "north");
	add_exit(ROOMS+"city2", "east");
	add_exit(ROOMS+"weapon_shop", "south");
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
}
}
