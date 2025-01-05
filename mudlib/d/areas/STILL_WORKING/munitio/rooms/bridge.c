//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "An earthen bridge");
	set("long", "A huge amount of earth and gravel has been piled up here to create a narrow, zig-zagging bridge up to the gates of Munitio. This bridge is the only apparent way on to the island; a wall built from tree trunks rings the island and large steel barbs have been planted in the earth below the walls, all the way down to the water line. Archers patrol the battlements on the walls, ready to rain down firey death at the first sign of trouble.");
set_items( (["bridge": "It's made out of wood and metal, and looks really strong.",
"water": "You see the jaws of some fish. They look like pirahnas.",
"battlements": "You'd think they were expecting the demons to attack again. They're very well-armed." ]) );
        add_exit("/d/damned/virtual/room_1_12.world", "out");
	add_exit(ROOMS+"gates", "north");
}
