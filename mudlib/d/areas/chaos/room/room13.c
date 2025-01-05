#include <std.h>

inherit ROOM;

void create() {
	::create();
	set("short", "A room");
	set_property("indoors", 2);
	set_exits( ({
	"road20.c",
}),
	({"north"}));
	set_smell("default", "The smell of burnt flesh penetrates your nostrils.");
}
