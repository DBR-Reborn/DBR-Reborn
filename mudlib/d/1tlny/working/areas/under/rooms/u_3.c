#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Cavern");
	set_long("You are standing in some underground caverns, it is very moist and humid in here.  The floor is covered with many pebbles and small patches of moss are found on the floor.");
	set_items(([
	"moss" : "The moss on the floor glows lightly in the ground.",
	"floor" : "The floor is covered with many pebbles and small patches of moss.",
	"pebbles" : "There are many different colors of pebbles here."
	]));
	set_listen("default", "You can hear the small rustling sound of the pebbles on the ground.");
	set_smell("default", "It air smells permeated with sweetness.");
	set_exits( ({
	"/wizards/blial/under/rooms/w_4",
	"/wizards/blial/under/rooms/u_4",
	"/wizards/blial/under/rooms/t_2",
	"/wizards/blial/under/rooms/v_3",
	}),({
	"north", "east", "south", "west"
	}));
}


