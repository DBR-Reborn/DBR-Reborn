#include <std.h>

inherit ROOM;

void create() {
	::create();
	set("short", "A room");
	set_property("indoors", 2);
	set_exits( ({
	"road20.c",
}),
	({"east"}));
	set_smell("default", "The air is permeated by soot and the smell of charcoal.");
}
