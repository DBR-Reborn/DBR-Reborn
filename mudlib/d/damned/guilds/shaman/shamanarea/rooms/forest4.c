//  Made by Tailwind for Shaman Area.
#include "../shamanarea.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 0);
    set("short", "In a dense section of the forest.");
    set("long", "This is a particularly dense part of the forest. You feel magic emanating from all around. In the middle of this particular section of the forest is an altar. To the east, you see a massive tree.");
set_items( (["altar": "Most people 'prostrate' themselves when dealing with altars.",
"trees": "You can't see the forest for the trees, can you?" ]) );
    set_smell("default", "The smell of energy and vitality here is intense.");
    set_listen("default", "You can just _smell_ the pure life here. It's indescribable.");
    add_exit(ROOMS+"forest7", "south");
    add_exit(ROOMS+"forest5", "east");
    add_exit(ROOMS+"forest1", "north");
    add_exit("/d/damned/guilds/join_rooms/shaman_join", "out");
}
void init() {
    ::init();
    add_action("prostrate_func", "prostrate");
    add_action("solve_func", "solution");
}

int prostrate_func(string str) {
    if(!str || str != "before altar") {
	write("Prostrate before what?\n");
	return 1;
    }

    if(this_player()->query_class() != "shaman"){
write("Nothing happens. Your prayers are rejected.");
return 1;
}


    write("You prostrate yourself before the altar, and a white angel appears in mid-air above it. She speaks: 'We are separated by seconds, not miles or days. We are all of the same mother, yet twins are we not. What are we?' (type 'solution <blah>')");
    return 1;
}

int solve_func(string str) {
object ob;
    if(!str || str != "triplets") {
	write("The angel frowns. 'That is not correct.'\n");
	return 1;
    }
    write("'That is correct,' the angel says with a dazzling smile. She disappears in a burst of white light, and something clatters on top of the altar. You pick it up.");
    ob = new("/std/tailwind/obj/shaman_symbol");
    ob->set_type("life");
    ob->move(this_player());
    return 1;
}
