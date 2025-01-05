//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Streets of Munitio");
	set("long", "You wonder about how the blacksmiths can take living in this dreary town. It seems as though the buildings and the streets are painted in nothing more than black and grey. Shops line the streets here. To your south, one shop in particular catches your eye - it is an armour shop. To the north, you can see several forges.");
set_items( (["shop": "Armour is sold at this one.",
"streets": "Since there are no cars, you walk on them.",
"buildings": "They hold things, such as people and objects.",
"blacksmiths": "You would recommend a new vocation for them. They look so depressed." ]) );
	add_exit(ROOMS+"city3", "west");
	add_exit(ROOMS+"city5", "north");
	add_exit(ROOMS+"city1", "east");
	add_exit(ROOMS+"armour_shop", "south");
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
