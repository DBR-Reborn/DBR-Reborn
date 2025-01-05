#include <std.h>

inherit ROOM;

void create() {
	::create();
	set("short", "A rrom");
	set_property("outdoors", 3);
	set_property("light", 3);
	set_exits( ({
	"road2.c",
	"xroads.c"}),
	({"north", "south"}));
}
