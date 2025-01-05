#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "South end of Livingstone street");
	set_long("This is the south end of Livingstone Street, more buildings are on fire here, while you can see the shadows of people running in and out of their houses, gathering things and the dead.");
	set_property("indoors", 2);
	set_property("light", 3);
	set_exits( ({
	"road7.c",
	"road5.c"}),
	({"north", "south"}));
}
void reset() {
	::reset();
	if(!present("warrior")) {
	new(MON+"kwarrior.c")->move(this_object());
	new(MON+"kwarrior.c")->move(this_object());
	new(MON+"peasant.c")->move(this_object());
	new(MON+"peasant.c")->move(this_object());
    }
}
