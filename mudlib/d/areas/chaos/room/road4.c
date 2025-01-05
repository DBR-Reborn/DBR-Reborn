#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "Further down the east road");
	set_long("This part of the east road has some buildings that aren't as destroyed as the others were, although all of them are pretty dangerous right now. Some bodies are scattered around in the shape of Chaos, the eight pointed star.  While blood and sinew are splattered everywhere.  You can't even see what type of buildings these used to be.");
	set_smell("default", "There is the smell of decay in the air.");
	set_property("light", 3);
	set_listen("default", "You hear some muffled screams to the east.");
	set_property("indoors", 2);
	set_exits( ({
	"road3.c", 
	"road5.c",
}),
	({"west", "east"}));
}
void reset() {
	::reset();
	if(!present("warrior")) {
	new(MON+"beastman.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
    }
	if(!present("warrior")) {
	new(MON+"kwarrior.c")->move(this_object());
	new(MON+"peasant.c")->move(this_object());
    }
}
