// generic underdark room for Vishnu

#include <std.h>
#include <vishnu.h>

inherit ROOM;

create() {
    	::create();
    	set_property("light",0);
    	set_property("indoors", 1);
    	set("short", "A winding cavern passageway.");
    	set("long", "The cavern's walls are very wide here. "
    		"Bones lay scattered about the floor, "
    		"showing that many people have died here.");
	set_items(([ ({"walls", "wall"}) : "The limestone walls are slimy and wet.",
		({"pillar", "pillars", "column", "columns"}) : "The giant "+
			"stalagmites tower above you, nearly reaching the ceiling.",
		"ceiling" : "The ceiling is covered with a spikey veil of stalactites."
			]));
	set_exits( ({ "drow03", "drow06", "drow06" }),
    		( { "east", "west", "north" } ) );
    	set_smell("default", "The smell of death is near.");
    	set_listen("default", "You hear the screams of the myconids.");
}
void reset() {
   	::reset();
    	if(!present("myconid")){
       	new(MON+"lmyconid.c")->move(this_object());
       	new(MON+"lmyconid.c")->move(this_object());
	}
}
