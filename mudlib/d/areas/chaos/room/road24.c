#include <std.h>

inherit ROOM;

void create() {
	::create();
	set("short", "A rrom");
	set_property("indoors", 2);
	set_exits( ({
	
	//"house3.c",
	"road25.c",
	//"house8.c",
	"road7.c"}),
	({
//"north", 
"east", 
//"south", 
"west"}));
}
