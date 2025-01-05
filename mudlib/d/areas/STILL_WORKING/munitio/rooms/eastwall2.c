//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The City Wall");
	set("long", "The wall here bends to the north east, following the natural curve of the island. The stone that the wall is made of is unnaturally strong. You wonder if they used some metal in making the wall.");
set_items( (["island": "Islands are continents, just smaller.",
"wall": "You're on top of it."]) );
	add_exit(ROOMS+"eastwall3", "northeast");
	add_exit(ROOMS+"eastwall1", "west");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"wallguard.c")->move(this_object());
	new(MON+"wallguard.c")->move(this_object());
}
}
