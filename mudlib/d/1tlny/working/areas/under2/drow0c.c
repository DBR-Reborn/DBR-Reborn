// generic underdark room for Vishnu

#include <std.h>
#include <vishnu.h>

inherit ROOM;

create() {
    	::create();
    	set_property("light",0);
    	set_property("indoors", 1);
    	set("short", "A winding cavern passageway.");
	set("long",
		"All around you, stalagmites poke out from the ground, their tips glistening with liquid"
		" from the water dripping from above.  On the cavern wall, there has been written some words."
		"They are probably from another adventurer, years ago."
	);
	set_items(([ ({"walls", "wall"}) : "The limestone walls are slimy and wet.",
		({"pillar", "pillars", "column", "columns"}) : "The giant "+
			"stalagmites tower above you, nearly reaching the ceiling.",
		"ceiling" : "The ceiling is covered with a spikey veil of stalactites."
			]));
    	set_exits( ({ "drow0a", "drow0d", "drow0c" }),
    		({ "east", "south", "west" }));
	set_smell("default", "You smell sulfur.");
	set_listen("default", "It is suspiciously quiet here.");
}
