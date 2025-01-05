//  Made by Tailwind for Shaman Area.
#include "../shamanarea.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 0);
    set("short", "In a dense section of the forest.");
    set("long", "This is a particularly dense part of the forest. You feel magic emanating from all around. In the middle of this particular section of the forest is an altar. To the south and west, you see a massive tree.");
set_items( (["altar": "Most people 'prostrate' themselves when dealing with altars.",
"trees": "You can't see the forest for the trees, can you?" ]) );
    set_smell("default", "The smell of dirt and dust pervades the air.");
    set_listen("default", "You think you hear a distant rumble.");
    add_exit(ROOMS+"forest2", "west");
    add_exit(ROOMS+"forest6", "south");
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


    write("You prostrate yourself before the altar, and a massive beast made of stone appears in mid-air above it. He speaks: 'You can see its parts easily - but often, people will miss its entirety. What is it?' (type 'solution <blah>')");
    return 1;
}

int solve_func(string str) {
object ob;
    if(!str || str != "forest") {
	write("The beast growls. 'That is not correct.'\n");
	return 1;
    }
    write("'That is correct,' the beast purrs. He disappears in a burst of green light, and something clatters on top of the altar. You pick it up.");
    ob = new("/std/tailwind/obj/shaman_symbol");
    ob->set_type("earth");
    ob->move(this_player());
    return 1;
}