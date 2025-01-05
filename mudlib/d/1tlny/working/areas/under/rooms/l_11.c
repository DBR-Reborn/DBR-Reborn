#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Tunnels");
	set_long("This is a large cavern, with an emmense ceiling filled with spider webs and objects stuck to them.  There is a passage to the west which is covered with a tapestry, as well as a tunnel that leads south.");
	set_items(([
	"webs" : "These are the webs of some horrid creature.",
	"tapestry" : "The tapestry has a strange glyph on it.",
	"glyph" : "The glyph looks like a spider with metal rings around its legs."
	]));
	set_listen("default", "You can hear your feet on the dry rock.");
	set_smell("default", "The scent of exotic herbs permeate your nostrils.");
	set_exits( ({
	"/wizards/blial/under/rooms/l_12",
	"/wizards/blial/under/rooms/l_10",
	"/wizards/blial/under/rooms/k_11",
	}),({
	"north", "south", "west"
	}));
}


