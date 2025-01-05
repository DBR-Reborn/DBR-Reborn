#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 1);
    set( "short", "Quarry road." );
    set( "day long", @EndText
The road continues downwards through the roughly cut walls
of stone. Looking east you see the wide path through the rock
leading towards a huge opening in the distance. Like tiny dots
you can see several beings down there. They must be the slaves
that work all day long breaking off the huge rocks that are to
be used to expand the great walls surrounding the village. To
the south there is some sort of guard post.
EndText
);
    set( "night long", @EndText
You keep moving through the darkness of the quarry. To the
east the road is sloping downwards between the natural walls.
South of here you see the vague contours of something that
looks like a guard post.

EndText
);
   
    set_exits( ({ ROOMS_PATH+"quarry_guard_post", ROOMS_PATH+"quarry_road3"
}), ({ "south", "east" }) );
}

