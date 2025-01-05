//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Streets of Munitio");
	set("long", "This is where the troops of Munitio are housed. Thier quarters don't look much better than the blacksmiths' houses, but they aren't quite as smashed together. There are off duty guards everywhere, eating, smoking, and telling jokes. You sigh, knowing that the smokers are poisoning everyone in the vicinity, and not just themselves.");
set_items( (["quarters": "They must be quarters because they're a fourth of the space normal people need to live.",
"smokers": "Smoking is bad.",
"eaters": "It's a much safer past-time than smoking.",
"guards": "They seem to be enjoying themselves for the most part." ]) );
	add_exit(ROOMS+"city13", "west");
	add_exit(ROOMS+"city8", "south");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"cityguard.c")->move(this_object());
	new(MON+"cityguard.c")->move(this_object());
	new(MON+"gateguard.c")->move(this_object());
	new(MON+"gateguard.c")->move(this_object());
	new(MON+"cityguard.c")->move(this_object());
}
}
