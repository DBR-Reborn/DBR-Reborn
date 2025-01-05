// generic underdark room for Vishnu

#include <std.h>
#include <vishnu.h>

inherit ROOM;

create() {
    	::create();
    	set_property("light",0);
    	set_property("indoors", 1);
    	set("short", "A winding cavern passageway.");
   	set(
   		"long",
   		"The cavern seems to get a bit wider here.  Maybe you have found the main chamber "
   		"of the myconids.  A few Myconid Adults pass by you periodically.  They "
   		"eye you suspiciously.  You get the feeling that you aren't very welcome."
   	);
	set_items(([ ({"walls", "wall"}) : "The limestone walls are slimy and wet.",
		({"pillar", "pillars", "column", "columns"}) : "The giant "+
			"stalagmites tower above you, nearly reaching the ceiling.",
		"ceiling" : "The ceiling is covered with a spikey veil of stalactites."
			]));
    	set_exits( ({ "drow04", "drow0a", "drow09" }),
    		({ "north", "south", "west" }));
   	set_listen("default", "You hear the shrieking of the myconids.");
   	set_smell("default", "It smells heaviliy of mushrooms here.");
}
