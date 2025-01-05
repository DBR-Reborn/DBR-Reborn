//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;
void create() {
	::create();
	set_pre_exit_functions( ({"ramp"}), ({"blocker"}) );
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The Streets of Munitio");
	set("long", "There is a small canal here seperating the lower class area of Munitio from the upper class area. An ornate ramp bridges the canal, and several guards stand watch to make sure no undesirables cross it.");
set_items( (["ramp": "It's made out of some really expensive and rare wood. The top is plated with gold so people won't screw up the wood underneath.",
"canal": "It's filled with Arkalian Jumping Killer Fish of Death.",
"undesirables": "Yes, that includes your ugly self.",
"guards": "They're not guarding you, so I would be careful." ]) );
	add_exit(ROOMS+"city12", "east");
	add_exit(ROOMS+"city9", "south");
	add_exit(ROOMS+"city14", "west");
	add_exit(ROOMS+"city15", "ramp");
}


void reset() {
	::reset();
if(!present("guard")){
	new(MON+"gateguard.c")->move(this_object());
	new(MON+"gateguard.c")->move(this_object());
	new(MON+"gateguard.c")->move(this_object());
}
}

int blocker() {
	if(present("guard")) {
	write("The guard looks you over and roughly pushes you back.");
	return 0;
	}
	else
	return 1;
}
