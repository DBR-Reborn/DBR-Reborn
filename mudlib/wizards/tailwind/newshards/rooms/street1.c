//  Made by Tailwind for New Shards.
#include "../newshards.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 0);
    set("short", "On the streets of a town.");
    set("long", "You are by the entrance of a very small village. The road is gravelly and rough. It continues to the south, where you see some crudely constructed buildings. A sign swings lazily in the slight wind.");
set_items( (["road": "It's constructed fairly badly - you guess there wasn't a lot of labor to go around. ",
"sign" : "It reads:\nWelcome to New Shards!\n" ]) );
    add_exit("/d/damned/virtual/room_15_15.underworld", "out");
    add_exit(ROOMS+"street2", "south");
}