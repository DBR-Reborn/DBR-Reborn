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
    		"There is a steep decline to the south.  It leads deeper into the cavern. "
    		"Some adult Myconids are gathered around, discussing important issues."
    		);
	set_items(([ ({"walls", "wall"}) : "The limestone walls are slimy and wet.",
		({"pillar", "pillars", "column", "columns"}) : "The giant "+
			"stalagmites tower above you, nearly reaching the ceiling.",
		"ceiling" : "The ceiling is covered with a spikey veil of stalactites."
			]));
    	set_exits( ({ "drow02", "drow09", "drow04" }),
		({ "west", "south", "east" }));
    	set_listen("default", "You hear a heated discussion.");
    	set_smell("default", "Something stinks.");
}
