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
	"You look over the secret room, seeing many pieces of broken pick-axes. "
	"The walls here are scratched lightly from some kind of tool, however "
	"they are less than 'damaged'."
	);
	set_items(([ ({"walls", "wall"}) : "The limestone walls are slimy and wet.",
		({"pillar", "pillars", "column", "columns"}) : "The giant "+
			"stalagmites tower above you, nearly reaching the ceiling.",
		"ceiling" : "The ceiling is covered with a spikey veil of stalactites."
			]));
	add_exit("drow08","up");

}

void reset() {
	::reset();
	if(!present("dwarven miner")) {
	new(MON+"miner")->move(this_object());
	}
}
