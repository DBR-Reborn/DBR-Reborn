#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Between two baracks." );
    set( "day long", @EndText
This room is brighter than the previous. When looking around
you notice there is quite some space between the walls.
Probably because rooms can be seen to the north and south.
To the east and west the road continues.
EndText
);
    set( "night long", @EndText
This room is brighter than the previous. When looking around
you notice there is quite some space between the walls.
Probably because rooms can be seen to the north and south.
To the east and west the road continues.
EndText
);
    set_exits( ({ ROOMS_PATH+"road", ROOMS_PATH+"road3", ROOMS_PATH+"nbarrack", ROOMS_PATH+"sbarrack" }), ({ "west", "east", "north", "south" }) );
}


