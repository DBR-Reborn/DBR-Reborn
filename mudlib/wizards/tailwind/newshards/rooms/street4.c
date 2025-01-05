//  Made by Tailwind for New Shards.
#include "../newshards.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 0);
    set("short", "On the streets of a town.");
    set("long", "You appear to be entering a nicer section of town, if you can call it that. Here, the buildings are only mildly dirty, and even appear to be made of more than loosely nailed together pieces of wood. There are even various wooden benches placed throughout the street. To your west is the Demon's Demise tavern. To the southeast, you spot a plain but extremely well-kept up building. The road continues to your southwest. ");
    add_exit(ROOMS+"street3", "north");
    add_exit(ROOMS+"street5", "southwest");
    add_exit(ROOMS+"tavern", "west");
    add_exit(ROOMS+"taulaltar", "southeast");
}
void init() {
    ::init();
    add_action("sit_fun", "sit");
}

int sit_fun(string str) {
if(!str) {
	notify_fail("Sit on what?\n");
	return 0;
    }
    if(str != "on bench") {
	notify_fail("You can't sit on that!\n");
	return 0;
    }
    write("You rest your weary bones on the bench. Suddenly, a hole opens up beneath it, and the bench parts in two! You fall through the hole, and land with a thud somewhere else.");
    this_player()->move(ROOMS+"girlsroom");
    return 1;
}