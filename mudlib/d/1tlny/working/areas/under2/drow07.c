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
    		"Not much to look at in this part of the cavern.  Just a few stalagmites that "
   		"are broken off.  Possibly, from something very big trying to fit through here."
   	);
	set_items(([ ({"walls", "wall"}) : "The limestone walls are slimy and wet.",
		({"pillar", "pillars", "column", "columns"}) : "The giant "+
			"stalagmites tower above you, nearly reaching the ceiling.",
		"ceiling" : "The ceiling is covered with a spikey veil of stalactites."
			]));
    	set_exits( ({ "drow03", "drow07", "drow07" }),
    		({ "northeast", "west", "south" }));
	set_listen("default", "You hear the shuffling of feet.");
	set_smell("default", "Something stinks nearby.");
}
