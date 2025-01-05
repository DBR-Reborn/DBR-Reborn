//  Made by Tailwind for Shaman Area.
#include "../shamanarea.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 0);
    set("short", "In a dense section of the forest.");
    set("long", "This is a particularly dense part of the forest. You feel magic emanating from all around. In the middle of this particular section of the forest is an altar. To the west, you see a massive tree.");
set_items( (["altar": "Most people 'prostrate' themselves when dealing with altars.",
"trees": "You can't see the forest for the trees, can you?" ]) );
    set_smell("default", "You smell the freshness of a light breeze.");
    set_listen("default", "The sound of a light wind whistling through the trees is unmistakable.");
    add_exit(ROOMS+"forest9", "south");
    add_exit(ROOMS+"forest5", "west");
    add_exit(ROOMS+"forest3", "north");
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

    write("You prostrate yourself before the altar, and a small cyclone appears in mid-air above it. It speaks: 'I am fire of a sort, yet am born from water. I am power incarnate, yet last for not a second. What am I?' (type 'solution <blah>')");
    return 1;
}

int solve_func(string str) {
object ob;
    if(!str || str != "lightning") {
	write("The cyclone appears to slow down for a second. 'That is not correct.'\n");
	return 1;
    }
    write("'That is correct,' the cyclone says in a whistle. It disappears in a great gust of wind, and something clatters on top of the altar. You pick it up.");
    ob = new("/std/tailwind/obj/shaman_symbol");
    ob->set_type("sky");
    ob->move(this_player());
    return 1;
}