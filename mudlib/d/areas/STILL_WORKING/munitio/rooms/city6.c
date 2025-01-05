//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Streets of Munitio");
	set("long", "At one point in the city's life, a blacksmith shop was located here. Unfortunately, the evil and cruel governor decided that this was 'not focused' enough, and closed it so the owners could work at the weapons and armour forges. To the north are several small houses and to the west you see the edge of the forge district.");
set_items( (["shop": "Ben's Blacksmith Depot, the old sign reads.",
"houses": "You have trouble believing people could live in these hellholes." ]) );
	add_exit(ROOMS+"city3", "south");
	add_exit(ROOMS+"city10", "north");
	add_exit(ROOMS+"city7", "west");
	add_exit(ROOMS+"city5", "east");
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