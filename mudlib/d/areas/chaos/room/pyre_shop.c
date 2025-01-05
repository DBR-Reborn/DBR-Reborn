#include <std.h>

inherit ROOM;

void create() {
	::create();
	set("short", "A simple house.");
	set("long", "This is a strange house, only strange because the house is very simple, maybe too simple.  It is made of wood, with 2 windows that look out into the street.");
	set_property("light", 3);
	set_property("indoors", 2);
	set_exits( ({
	"road17.c",
}),
	({"east"}));
	set_smell("default", "The air is permeated by soot and the smell of charcoal.");
}
