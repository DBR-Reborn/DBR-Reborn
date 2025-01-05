// generic underdark room for Vishnu

#include <std.h>
#include <vishnu.h>

inherit ROOM;

create() {
    	::create();
    	set_property("light",0);
    	set_property("indoors", 1);
    	set("short", "A winding cavern passageway.");	
	set("long", "Here is a little spring.  The water seaps up from the cave floor, making a little pool.  The overflow runs to the west, making a quiet little stream.");
	set_items(([ ({"walls", "wall"}) : "The limestone walls are slimy and wet.",
		({"pillar", "pillars", "column", "columns"}) : "The giant "+
			"stalagmites tower above you, nearly reaching the ceiling.",
		"ceiling" : "The ceiling is covered with a spikey veil of stalactites."
			]));
	set_smell("default", "You smell sulfur.");
	set_listen("default", "You hear the gentle stream.");
	set_exits( ({ "drow0c", "drow0e", "drow0d", "drow01" }),
		({ "north", "east", "southwest", "south" }));
}
