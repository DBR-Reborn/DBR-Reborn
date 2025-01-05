//  Made by Tailwind for New Shards.
#include "../newshards.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 0);
    set("short", "On the streets of a town.");
    set("long", "You have finally reached the end of the town's main road. Before you to the south is the largest structure of the town - a church. A smaller and less ornate building is to the west. The street continues to the northeast.");
    add_exit(ROOMS+"street4", "northeast");
    add_exit(ROOMS+"church", "south");
    add_exit(ROOMS+"undermine_shop", "west");
}
