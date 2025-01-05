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
    		"The walls here are flat and slick.  The ceiling is barely above your head here, "
    		"making you feel somewhat closed in.  Now would probably be a good time to "
    		"turn back if you are claustrophobic, since the path ahead looks even more narrow."
    	);
	set_items(([ ({"walls", "wall"}) : "The limestone walls are slimy and wet.",
		({"pillar", "pillars", "column", "columns"}) : "The giant "+
			"stalagmites tower above you, nearly reaching the ceiling.",
		"ceiling" : "The ceiling is covered with a spikey veil of stalactites."
			]));
    	set_exits( ({ "drow09", "drow0c", "drow0b", "drow0a" }),
    		({ "north", "west", "east", "northeast" }));
	set_smell("default", "Something is rotting nearby.");
	set_listen("default", "It is awfully quiet.");
}
