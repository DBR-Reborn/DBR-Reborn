#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "The intersection of Market Street and West Road.");
	set("long", "This is the intersection of Market Street and West Road, the buildings here are very strange indeed, all of them are constantly shifting forms and color. While some of them have eyes that pierce through your eyes and into your soul.");
	set_smell("default", "As you smell the strange aroma, you feel your nostrils changing.");
	set_property("light", 3);
	set_listen("default", "You hear the sounds of weddings, funerals, and births.");
	set_property("indoors", 2);
	set_exits( ({
	"road19.c",
	"road21.c",
	"room13.c",
	"room12.c"}),
	({"north", "east", "south", "west"}));
}
void reset() {
	::reset();
	if(!present("champion")) {
	new(MON+"tzeentchc.c")->move(this_object());
	new(MON+"twarrior.c")->move(this_object());
	new(MON+"twarrior.c")->move(this_object());
    }
}
