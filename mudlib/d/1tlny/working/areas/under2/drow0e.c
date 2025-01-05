// generic underdark room for Vishnu

#include <std.h>
#include <vishnu.h>

inherit ROOM;

create() {
	::create();
	set_property("light",0);
	set_property("indoors", 1);
	set("short", "A winding cavern passageway.");
	set("long", "The rock walls jut out roughly here.  The path slopes up to the east, going somewhere.");
	set_items(([ ({"walls", "wall"}) : "The limestone walls are slimy and wet.",
		({"pillar", "pillars", "column", "columns"}) : "The giant "+
			"stalagmites tower above you, nearly reaching the ceiling.",
		"ceiling" : "The ceiling is covered with a spikey veil of stalactites."
			]));
	set_smell("default", "The smell of mushrooms is coming from everywhere.");
	set_listen("default", "The walls are talking to you man!");
	set_exits( ({ "drow0d", "drow0g", "drow0a", "drow0e" }),
		({ "west", "east", "north", "south" }));
}
