#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Tunnel");
	set_long("The underground tunnels stretch hundreds of feet long, while only being about 4 feet wide, you find yourself in a slight state of claustrophobia.  The tunnel continues north into the darkness.");
	set_items(([
	"cave" : "The caves stretch out as far as the eye can see in the dark.",
	"floor" : "The floor of this cavern is damp and slippery.",
	]));
	set_smell("default", "The air is cold without any distinct smell.");
	set_listen("default", "You can only hear the droplets of water as they splash onto the ground.");
	set_exits( ({
	"/wizards/blial/under/rooms/o_2",
	}),({
	"north"
	}));
}


