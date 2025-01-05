//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Streets of Munitio");
	set("long", "This watch tower is very solidly built, apparently out of some very strong stone. The top of the tower is the highest point on the island and you can see a long way out over the ocean. You think you can even make out Daybreak Ridge, even at this distance.");
set_items( (["Daybreak Ridge": "It's the happening spot for adventurers like you." ]) );
	add_exit(ROOMS+"city15", "southwest");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"ucguard.c")->move(this_object());
	new(MON+"ucguard.c")->move(this_object());
	new(MON+"gateguard.c")->move(this_object());
}
}
