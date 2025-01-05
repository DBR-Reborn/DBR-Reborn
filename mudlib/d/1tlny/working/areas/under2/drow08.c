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
    		"The rock walls here have been scarred by the metal of pick axes. "
    		"Many adventurers have probably roamed these caverns, "
    		"in search of minerals.  It seems very unlikely that they found anything "
   		"at all."
    	);
	set_items(([ ({"walls", "wall"}) : "The limestone walls are slimy and wet.",
		({"pillar", "pillars", "column", "columns"}) : "The giant "+
			"stalagmites tower above you, nearly reaching the ceiling.",
		"ceiling" : "The ceiling is covered with a spikey veil of stalactites."
			]));
    	set_exits( ({ "drow03", "drow08", "drow08" }),
    		({ "northwest", "south", "east" }));
    	add_exit("drow0f","down");
	set_invis_exits( ({"down"}) );
	set_listen("default", "You hear metal scraping, possibly someone " 
    		"sharpening something.");
    	set_smell("default", "If you could smell fear, you'd probably smell it.");
}
    void reset() {
      ::reset();
     if(!present("donkey")) {
    new(MON+"donkey.c")->move(this_object());
}
}
