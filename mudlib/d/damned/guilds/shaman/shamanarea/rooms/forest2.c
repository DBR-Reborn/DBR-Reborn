//  Made by Tailwind for Shaman Area.
#include "../shamanarea.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 0);
    set("short", "In a dense section of the forest.");
    set("long", "This is a particularly dense part of the forest. You feel magic emanating from all around. In the middle of this particular section of the forest is an altar. To the south, you see a massive tree.");
set_items( (["altar": "Most people 'prostrate' themselves when dealing with altars.",
"trees": "You can't see the forest for the trees, can you?" ]) );
    set_smell("default", "The smell of smoke is quite noticable.");
    set_listen("default", "The sound of crackling flames pervades the area, yet you see nothing that is burning.");
    add_exit(ROOMS+"forest1", "west");
    add_exit(ROOMS+"forest5", "south");
    add_exit(ROOMS+"forest3", "east");
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


    write("You prostrate yourself before the altar, and a man dressed in red appears in mid-air above it. He speaks: 'With the blow of wind she flares up, and dies as soon as she drinks water. She is a pretty woman, although not really - just rather feminine. What is it?' (type 'solution <blah>')");
    return 1;
}

int solve_func(string str) {
object ob;
    if(!str || str != "fire") {
	write("The man shakes his head. 'That is not correct.'\n");
	return 1;
    }
    write("'That is correct,' the man nods. He disappears in a burst of red light, and something clatters on top of the altar. You pick it up.");
    ob = new("/std/tailwind/obj/shaman_symbol");
    ob->set_type("fire");
    ob->move(this_player());
    return 1;
}