#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("outdoors", 1);
	set("short", "Further down the plains.");
	set("long", "Walking down further the long path you notice something far of in the distance, smoke you think to yourself.  Could it be a fire or just a fireplace burning.");
	set_property("light", 3);
	set_exits( ({
	"plains1.c", 
	"plains3.c"}),
	({"south", "north"}));
	set_smell("default", "The air is fresh.");
}
