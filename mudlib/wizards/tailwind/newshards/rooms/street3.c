//  Made by Tailwind for New Shards.
#include "../newshards.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 0);
    set("short", "On the streets of a town.");
    set("long", "The road, little more than a gravelly path to your northeast, finally hardens into something that is easily traversed by pulled carts. To your north, east, and west, you see stores of varying sorts. To the south, you see more assorted buildings, and what you think is a tavern.");
    add_exit(ROOMS+"street2", "northeast");
    add_exit(ROOMS+"street4", "south");
    add_exit(ROOMS+"weaponshop", "west");
    add_exit(ROOMS+"armourshop", "east");
    add_exit(ROOMS+"generalshop", "north");
}
