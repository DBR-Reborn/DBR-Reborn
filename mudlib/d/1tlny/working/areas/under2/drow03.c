// generic underdark room for Vishnu

#include <std.h>
#include <vishnu.h>

inherit ROOM;

create() {
    	::create();
    	set_property("light",-1);
    	set_property("indoors", 1);
    	set("short", "A winding cavern passageway.");
	set("long",
    		"The cavern comes to an intersection of paths here. So many "
    		"different ways to choose from.  Hopefully, there's nothing "
     		"bad down any of them."
     		);
	set_items(([ ({"walls", "wall"}) : "The limestone walls are slimy and wet.",
		({"pillar", "pillars", "column", "columns"}) : "The giant "+
			"stalagmites tower above you, nearly reaching the ceiling.",
		"ceiling" : "The ceiling is covered with a spikey veil of stalactites."
			]));
	set_exits( ({ "drow02", "drow07", "drow05", "drow06", "drow08"}),
    		( { "east", "southwest", "north", "west", "southeast"}));
	set_smell("default", "Smells like dung.");
	set_listen("default", "You hear a donky");
}
