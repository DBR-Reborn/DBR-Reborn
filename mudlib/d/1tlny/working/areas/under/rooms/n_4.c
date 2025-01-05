#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Cavern");
	set_long("After walking for a long time, you are gratified to see that the tunnel has ended in to a large cavern.  The cavern itself is about 20 feet tall and about as large as a medium sized caravan.
	");
	set_items(([
	"floor" : "The floor is covered with about 1 inch of water.",
	"water" : "The water seems to flow down into the tunnels that connect this cavern.",
	]));
	set_listen("default", 
	"You can hear the sound of water rushing through tunnels."
	);
	set_smell("default",
	"The smell of damp air assaults your nose."
	);
	set_exits( ({
	"/wizards/blial/under/rooms/n_3",
	"/wizards/blial/under/rooms/n_5",
	"/wizards/blial/under/rooms/m_4",
	}),({
	"south", "north", "west",
	}));
}


