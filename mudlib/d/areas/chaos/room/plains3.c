#include <std.h>

inherit ROOM;

void create() {
	::create();
	set("short", "Down the road");
	set("long", "This road seems to span for miles, there is nothing to see  except for the strangely perculiar smoke coming off from the distance.  The grass on the side of the road seems to be trampled quite a bit, and the road that you are standing on seems to be squashed out of shape by some hoof prints.");
	set_property("outdoors", 1);
	set_property("light", 3);
	set_exits( ({
	"plains2.c",
	"kislevent.c"}),
	({"south", "north"}));
	set_smell("default", "The air is thick and musty.");
}
