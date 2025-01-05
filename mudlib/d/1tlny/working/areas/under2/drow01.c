//      from the Nightmare mudlib
//      an example workroom for new immortals

#include <std.h>
#include <vishnu.h>

inherit ROOM;

void create() {
    	::create();
    	set_property("light", 1);
    	set_property("indoors", 1);
	set("short", 
		"The opening of a large cavern.\n"
		);
	set("night long", 
		"Your eyes adjust to the light of "
		"several torches in the entry-way. "
		"Stalagmites on the floor create pillars, "
		"almost reaching the ceiling."
		);
	set("day long", 
		"Stalagmites jut up from the ground making "
		"nice pillars that almost reach the ceiling."
		);
	set_exits( ({ "drow02", "/wizards/vishnu/workroom" }),
		({ "south", "vishnu" })
    		);
	set_items(([ ({"walls", "wall"}) : "The limestone walls are slimy and wet.",
		({"pillar", "pillars", "column", "columns"}) : "The giant "+
			"stalagmites tower above you, nearly reaching the ceiling.",
		"ceiling" : "The ceiling is covered with a spikey veil of stalactites."
			]));
	set_smell("default", "The musky smell of limestone is in the air.");
	set_listen("default", "You can hear the water trickling from above.");
	set_items(([ ({"stalagmite", "stalagmites", "pillar", "pillars"}) : 
        	  "Huge formations of rock, formed by years of dripping limestone.\nThey nearly touch the cavern ceiling." ]));
}
