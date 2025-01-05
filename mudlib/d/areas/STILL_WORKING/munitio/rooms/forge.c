//  coded by Triskadekta
#include "../munitio.h"
#include <std.h>

inherit ROOM;

object ob;

void create() {
	::create();
	
	set_property("light", 1);	
	set_property("indoors", 0);
	set("short", "The public forge");
	set("long", "Several citizens are here, working on personal projects. Half a dozen forges are set up in this room, and there's space for you to work if you so desire. You note that the guards are not watching you, and probably will not put a sword in your back if you try to use one.");
set_items( (["forges": "Hot. Very hot.",
"guards": "The guards are doing their best to ignore you - why can't you return the favor?" ]) );
	add_exit(ROOMS+"city7", "out");

}

void reset() {
	object forge;
	::reset();
	if(!present("guard")){
        new(MON+"cityguard.c")->move(this_object());
}
        if(!present("forge")) {
	ob=new("/wizards/diewarzau/obj/misc/greater_forge");
        ob->set_weight(250000);
        ob->move(this_object());
}
}