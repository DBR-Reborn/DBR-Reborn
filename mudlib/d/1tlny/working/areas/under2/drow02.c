// The underdark room
// drow02.c
// by vishnu

#include <std.h>
#include <vishnu.h>

inherit ROOM;

void create() {
    	::create();
	set_property("light", -1);
    	set_property("indoors", 1);
	set("short", "Another section of endless cavern");
	set("night long", "The intricacy of the cavern walls is amazing.\nMany of the rocks seem to take on the shape of faces.");
	set("day long", "The intricacy of the cavern walls is amazing.\nMany of the rocks seem to take on the shape of faces.");
	set_exits( ({ "drow03", "drow04", "drow01" }),
	    	({ "west", "east", "north" })
    		);
	set_items(([ ({"walls", "wall"}) : "The limestone walls are slimy and wet.",
		({"pillar", "pillars", "column", "columns"}) : "The giant "+
			"stalagmites tower above you, nearly reaching the ceiling.",
		"ceiling" : "The ceiling is covered with a spikey veil of stalactites."
			]));
	set_smell("default", "The smell of dank limestone is in the air.");
	set_listen("default", "You hear murmuring to the west.");
	set_items(( ["rocks" : "Many of the rocks look like faces", "faces" : "There's the face of K'Thach, and the face of Draxanar.", "walls" : "There are many facelike formations of rock on them" ]));
}
void reset() {
    	::reset();
    	if(!present("myconid")) {
    	new(MON+"myconid.c")->move(this_object());
	}
}
