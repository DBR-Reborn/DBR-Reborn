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
The temple corridor stretches north and south from
here. On your eastern and western sides are alcoves
that seem to function as guard rooms. Enshrouded in
the light from many burning torches you feel peace-
ful, yet this place is sacred to the storm giants
and you obviously dont belong here.
EndText
);
    add_item("torches", "Torches are securely fastened to the walls.");
    set_listen("default", "You hear a deep murmuring sound somewhere from
the north.");
    set_exits( ({ ROOMS_PATH+"temple_corridor1",
ROOMS_PATH+"temple_corridor3", ROOMS_PATH+"temple_east_post",
ROOMS_PATH+"temple_west_post" }), ({ "south", "north", "east", "west" }) );
}

