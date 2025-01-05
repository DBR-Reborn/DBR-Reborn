//  Made by Tailwind for Shaman Area.
#include "../shamanarea.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 0);
    set("short", "In a dense section of the forest.");
    set("long", "This is a particularly dense part of the forest. You feel magic emanating from all around. In the middle of this particular section of the forest is an altar. To the south and east, you see a massive tree.");
set_items( (["altar": "Most people 'prostrate' themselves when dealing with altars.",
"trees": "You can't see the forest for the trees, can you?" ]) );
    set_smell("default", "You smell death in the air.");
    set_listen("default", "The forest is absolutely quiet here. No sounds _at all_.");
    add_exit(ROOMS+"forest4", "south");
    add_exit(ROOMS+"forest2", "east");
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
    write("You prostrate yourself before the altar, and a giant skull appears in mid-air above it. It speaks: 'You began as it, and you shall end as it. It is insignificant, yet fills the world. What is it?' (type 'solution <blah>')");
    return 1;
}

int solve_func(string str) {
object ob;
    if(!str || str != "dust") {
	write("The talking skull gives a horrifying laugh. 'That is not correct.'\n");
	return 1;
    }

if(this_player()->query_class() == "shaman"); {
    write("'That is correct,' the skull notes with approval. It disappears in a flash of darkness, and something clatters on top of the altar. You pick it up.");
    ob = new("/std/tailwind/obj/shaman_symbol");
    ob->set_type("death");
    ob->move(this_player());
    return 1;
}
else {
write("'That is correct,' the skull notes with approval. It disappears in a flash of darkness.");
}
}
