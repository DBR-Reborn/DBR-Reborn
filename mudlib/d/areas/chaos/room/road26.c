#include <std.h>

inherit ROOM;

void create() {
	::create();
	set("short", "A rrom");
	set_property("indoors", 2);
	set_exits( ({
	
	//"house5.c",
	//"house9.c",
	//"house7.c",
	"road25.c",
}),
	({
//"north", 
//"east", 
//"south", 
"west"}));
}
