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
    		"This is the myconid nursery.  Many Myconid young are brought into "
   		"this world in this room.  The little mushroom-like creatures ponder about "
   		"clumsily."
    	);
	set_items(([ ({"walls", "wall"}) : "The limestone walls are slimy and wet.",
		({"pillar", "pillars", "column", "columns"}) : "The giant "+
			"stalagmites tower above you, nearly reaching the ceiling.",
		"ceiling" : "The ceiling is covered with a spikey veil of stalactites."
			]));
	set_exits( ({ "drow03", "drow05", "drow05" }),
    		( { "south", "north", "west" }));
    	set_smell("default", "It smells like fresh mushrooms here");
    	set_listen("default", "You here the newborn crying");
}
void reset() {
   	::reset();
    	if(!present("myconid")){
       	new(MON+"lmyconid.c")->move(this_object());
       	new(MON+"lmyconid.c")->move(this_object());
       	new(MON+"lmyconid.c")->move(this_object());
       	new(MON+"lmyconid.c")->move(this_object());
	}
}
