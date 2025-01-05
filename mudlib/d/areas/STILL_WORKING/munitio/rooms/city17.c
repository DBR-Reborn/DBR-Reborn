//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Streets of Munitio");
	set("long", "The western edge of the upper island is given over to a very small park. A couple of well dressed children are frolicking merrily in the sand box. A well-made playground lies next to the sandbox, where more children jump and play happily. A single guard watches over them as they enjoy themselves in the shadow of the city wall.");
set_items( (["children": "The kids look so innocent... and easy to kill! MUAHAHAHAHA! (Go see a shrink, sicko.)",
"guard": "You'd swear he was a child molestor. Look at those shifty eyes, and that weird smile.",
"sandbox": "It's a box. It contains: sand.",
"playground": "Swings, see-saw, slide, it has the works." ]) );
	add_exit(ROOMS+"city16", "east");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"ucguard.c")->move(this_object());
}
if(!present("aristocracy")){
	new(MON+"aristocracy.c")->move(this_object());
	new(MON+"aristocracy.c")->move(this_object());
}
}
