//  Made by Tailwind for New Shards.
#include "../newshards.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 0);
    set("short", "On the streets of a town.");
    set("long", "The road here, like at the entrance, is still quite rough. The road continues southwest, where you see what appears to be the bulk of the town. However, to your east is a small hut. ");
    add_exit(ROOMS+"street3", "southwest");
    add_exit(ROOMS+"magehut", "east");
    add_exit(ROOMS+"street1", "north");
}