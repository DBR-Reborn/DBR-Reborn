//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Streets of Munitio");
	set("long", "This is the upper class area of Munitio. The houses are fairly large considering the limited real estate, some even have small gardens in front. There are a few guards here and there to keep the peace, but not as many as in the low class part of town. To the north you see an almost palatial residence, which must be the home of Munitio's mayor or governor.");
set_items( (["houses": "These are veritable palaces compared to the horrible things the lower-class has to live in!",
"gardens": "Pretty flowers. You feel the urge to eat them, but remember that you're not a cow.",
"palace": "The governor lives in a huge house. The lesser people live in tiny ones. You feel yourself begin to anger.",
"guards": "The guards look a lot more relaxed up here." ]) );
	add_exit(ROOMS+"city16", "west");
	add_exit(ROOMS+"tower", "northeast");
	add_exit(ROOMS+"city13", "ramp");
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
