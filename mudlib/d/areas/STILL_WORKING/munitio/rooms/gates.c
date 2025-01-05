//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Gates of Munitio");
	set("long", "The gates of Munitio are an impressive feat of engineering. The huge wood and steel gates tower some 30 feet in the air, rising some 10 feet above the walls themselves. Near the top a section of each gate is cut out and it appears that guards wait with boiling oil or perhaps something even nastier to keep battering rams and such away from the gate. Just inside the gates ladders lead up to the walls on the east and west. To the north the city itself is crammed within the walls.");
set_items( (["gates": "They're big, OK? Really big!",
"guards": "A couple nearly dump some burning oil on you. Jerks.",
"ladders": "They're made of wood. You climb them." ]) );
	add_exit(ROOMS+"eastwall1", "east");
	add_exit(ROOMS+"westwall1", "west");
	add_exit(ROOMS+"city1", "north");
	add_exit(ROOMS+"bridge", "south");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"gateguard.c")->move(this_object());
	new(MON+"gateguard.c")->move(this_object());
}
}
