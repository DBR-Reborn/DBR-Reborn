#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set( "short", "Temple Corridor." );
    set( "long", @EndText
Shadows created by the numerous burning torches run
up and down the walls stretching up to the ceiling
of this corridor. North from here there is what
seems to be the end of the corridor, an enormous
wooden door. Further south the hallway leads out
from the temple.
EndText
);
    add_item("torches", "Torches are securely fastened to the walls.");
    set_listen("default", "You hear a deep murmuring sound coming from the
north.");
    set_exits( ({ ROOMS_PATH+"temple_corridor2",
ROOMS_PATH+"temple_corridor4" }), ({ "south", "north" }) );
}

