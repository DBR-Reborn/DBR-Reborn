#include <std.h>

inherit ROOM;

void create() {
	::create();
	set("short", "A rrom");
	set_property("indoors", 2);
	set_property("light", 3);
	set_exits( ({
	//"gentrance.c",
	"road1.c",
	//"alley3.c"
}),
	({//"north", 
"south", 
//"west"
}));
}
