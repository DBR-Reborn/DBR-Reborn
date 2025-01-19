#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set_short("Along west road.");
	set("long", "This is along West Road, to the west you can see many of the buildings warps with chaos.  Burning with a wild fire of green and blue, the shops and houses become destroyed.");
	set_smell("default", "You don't smell anything.");
	set_property("light", 3);
	set_listen("default", "There is nothing to hear, except for the sounds of death.");
	set_property("indoors", 2);
	set_exits( ({
	"road23.c",
	"road21.c",
}),
	({"east", "west"}));
}
void reset(){
	::reset();
	if(!present("beastman")) {
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
    }
}
