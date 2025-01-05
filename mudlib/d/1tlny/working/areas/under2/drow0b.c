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
		"This is the great room of the Elder Myconid. "
    		"Here is where the Myconids gather to discuss important issues "
    		"that are set forth to the Grand Council."
    	);
	set_items(([ ({"walls", "wall"}) : "The limestone walls are slimy and wet.",
		({"pillar", "pillars", "column", "columns"}) : "The giant "+
			"stalagmites tower above you, nearly reaching the ceiling.",
		"ceiling" : "The ceiling is covered with a spikey veil of stalactites."
			]));
    	set_exits( ({ "drow0a", "drow0b" }),
    		({ "west", "north" }));
    	set_listen("default", "It is quite serene and reverant here.");
}
void reset() {
    	::reset();
    	if(!present("drow")) {
    	new(MON+"drowscout.c")->move(this_object());
	}
}
