// generic underdark room for Vishnu

#include <std.h>
#include <vishnu.h>

inherit ROOM;

create() {
    	::create();
    	set_property("light",0);
    	set_property("indoors", 1);
    	set("short", "A winding cavern passageway.");
	set("long", "This must be the end of the caves... For now.  On the ground you see a hole with a ladder going down.  You wonder what may be in store for you down there.");
	set_items(([ ({"walls", "wall"}) : "The limestone walls are slimy and wet.",
		({"pillar", "pillars", "column", "columns"}) : "The giant "+
			"stalagmites tower above you, nearly reaching the ceiling.",
		"ceiling" : "The ceiling is covered with a spikey veil of stalactites."
			]));
	set_smell("default", "The smell of cooking rotting flesh wafts up from the hole.");
	set_listen("default", "You hear water trickling from the ceiling.");
    	set_exits( ({ "drow0e", "a4" }),
    		({ "west", "down" }));
}
void reset() {
	::reset();
	if(!present("drow")) {
	new(MON+"drowscout.c")->move(this_object());
	}
}
