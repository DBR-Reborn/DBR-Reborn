#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "North end of Market Street.");
	set("long", "This is the North end of Market Street, buildings burn hard, while a layer of decay rests upon each and everything in this general area. Off to the east is a dark alley, you can't see anything past a few feet of the entrance to it.");
	set_property("indoors", 3);
	set_property("light", 3);
	set_smell("default", "It smells like a warm coroners office here.");
	set_listen("default", "Laughter is in the air.");
	set_exits( ({
	"road15.c",
	"alley1.c",
	"road17.c"}),
	({"north", "east", "south"}));
}
void reset() {
	::reset();
	if(!present("warrior")) {
	new(MON+"nwarrior.c")->move(this_object());
	new(MON+"nwarrior.c")->move(this_object());
	new(MON+"nwarrior.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
    }
}
