//  Made by Tailwind for Shaman Area.
#include "../shamanarea.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    set_post_exit_functions( ({"enter"}), ({"enter_func"}) );   
    set_property("light", 4);
    set_property("indoors", 0);
    set("short", "Before the Tree.");
    set("long", "You are standing in front of a truly massive tree. It must be _thousands_ of years old! Around you is a dense forest, with trees much smaller than this one, but still pretty big.");
set_items( (["tree": "It's a big oak tree. It has roots which reach deep into the ground. As you look closer, you notice it has some old carvings in it.",
"carvings": "They read: stoor ta kool",
"roots": "One of them looks a bit loose - maybe you could 'dislodge' it?" ]) );
    set_smell("default", "It smells like a forest. You know, trees and animals.");
    set_listen("default", "You hear fuzzy little critters scampering about.");
    add_exit(ROOMS+"forest4", "west");
    add_exit(ROOMS+"forest8", "south");
    add_exit(ROOMS+"forest6", "east");
    add_exit(ROOMS+"forest2", "north");
}

void init() {
    ::init();
    add_action("dislodge_func", "dislodge");
}

int dislodge_func(string str) {
    if(!str || str != "root") {
	write("Dislodge what?\n");
	return 1;
    }

    write("You grab the root and push and pull and kick it until it finally moves. A hidden door swings open in the tree trunk.");
    add_exit("/d/damned/guilds/join_rooms/shaman_join.c", "enter");
    return 1;
}

int enter_func() {
write("The door swings shut behind you.");
remove_exit("enter");
        return 1;
}