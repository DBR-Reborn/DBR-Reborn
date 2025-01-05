#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set_short("Underground Tunnel");
	set_long("This section of the tunnel seems to come to an abrupt dead end, but you can hear the water that was pouring down from the other part of the tunnel flowing through here.");
	set_items(([
	"water" : "You can hear it going somewhere.",
	"wall" : "There is a crack in the wall where the water flows through, it looks like you might be able to fit inside it.",
	]));
	set_listen("default", 
	"You can hear water flowing through here."
	);
	set_smell("default",
	"You can smell the sour smell of damp moss."
	);
	set_exits( ({
	"/wizards/blial/under/rooms/n_4",
	"/wizards/blial/under/rooms/p_4",
	}),({
	"south", "southeast"
	}));
	add_exit("n_6", "north");
	add_invis_exit("north");
	set_pre_exit_functions(({"north"}), ({"go_north"}));
}



int go_north(){
	int xlevel;
	xlevel = this_player()->query_level();
	if(xlevel > 15){
	if(present("rock")){
	write("There is a rock in the way!");
	return 0;
	}
	else return 1;
	}
	else return 1;
	}
void reset(){
	::reset();
	if(!present("rock"))
	new("/wizards/blial/under/weapons/rock")->move(this_object());
}
