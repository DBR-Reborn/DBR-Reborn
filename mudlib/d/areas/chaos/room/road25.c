#include <std.h>

inherit ROOM;

void create() {
	::create();
	set("short", "A rrom");
	set_property("indoors", 2);
	set_exits( ({
	
	//"house4.c",
	"road26.c",
	//"house1.c",
	"road24.c"}),
	({//"north", 
"east", 
//"south", 
"west"}));
}
