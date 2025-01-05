#include <std.h>

inherit ROOM;

void create() {
	::create();
	set("short", "A rrom");
	set_property("indoors", 2);
	set_exits( ({
	"plains2.c",
	"burnthouse.c",
	"kislevent.c"}),
	({"south", "west", "north"}));
	set_smell("default", "The air is fresh.");
}
