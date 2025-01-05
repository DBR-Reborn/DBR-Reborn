//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Streets of Munitio");
	set("long", "There are very nice houses along the road leading up to the governor's residence, which lies just to the north. In comparison to what you saw in the poorer section of Munitio, they look palatial. There are even a few trees along the edges of the street. Their green leaves provide much in the way of shade.");
set_items( (["houses": "They look very nice and fancy.",
"trees": "You realize with a start that there are none on the lower level.",
"leaves": "Before you can stop yourself, you grab a couple and eat them. Yum!",
"shade": "It's darker than the unshaded places." ]) );
	add_exit(ROOMS+"city15", "east");
	add_exit(ROOMS+"city18", "north");
	add_exit(ROOMS+"city17", "west");
}
void reset() {
	::reset();
if(!present("guard")){
	new(MON+"ucguard.c")->move(this_object());
}
if(!present("aristocracy")){
	new(MON+"aristocracy.c")->move(this_object());
	new(MON+"aristocracy.c")->move(this_object());
	new(MON+"aristocracy.c")->move(this_object());
}
}
