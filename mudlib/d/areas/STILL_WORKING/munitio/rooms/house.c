//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	set_pre_exit_functions( ({"garden"}), ({"blocker"}) );
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The governor's house");
	set("long", "This house is extremely spartan. The single room is mostly dominated by a forging area, surrounded by several old and formidable blacksmiths. A small office area is set up in the northwest corner. This building seems out of place in the upper-class section of Munitio.");
set_items( (["office": "It has a little desk and lamp.",
"desk": "Nothing inside. You guess the governor offloads his work to others.",
"forges": "If you don't know what a forge is by now, ask a merchant.",
"blacksmiths": "They're big, burly, and ignoring you." ]) );
	add_exit(ROOMS+"garden", "garden");
	add_exit(ROOMS+"city18", "out");
}


void reset() {
	::reset();
if(!present("wrath")){
	new(MON+"wrath.c")->move(this_object());
}
}

int blocker() {
	if(present("wrath")) {
	write("The wrath swipes at your throat, nearly taking your head off!");
	return 0;
	}
	else
	return 1;
}
