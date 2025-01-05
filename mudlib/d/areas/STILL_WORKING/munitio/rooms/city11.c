//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Streets of Munitio");
	set("long", "A fairly large orphanage leans against the city wall at the western edge of the housing district. A small sign on the front proclaims that these childrens' parents died in the service of Munitio. Several small children are playing on the small scrap of grass in front of the building.");
set_items( (["orphanage": "It's where you store kids that don't have parents. This one looks kinda nice.",
"sign": "Dedicated to those who died in the Forge Fires.",
"children": "Stop looking at little kids, you pedeophile." ]) );
	add_exit(ROOMS+"city10", "east");
	add_exit(ROOMS+"city7", "south");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"cityguard.c")->move(this_object());
}

if(!present("citizen")){
	new(MON+"citizen.c")->move(this_object());
	new(MON+"citizen.c")->move(this_object());
}
}
