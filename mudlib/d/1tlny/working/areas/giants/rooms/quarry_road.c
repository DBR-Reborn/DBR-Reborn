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
The huge road leading into the quarry bends here. To the west
the road stretches out through the entrance towards the market-
place. To the north you can see some sort of guard post. Boulders
the size of an average human being are scattered across the area
and seem to be only shards from the enormous blocks that the giants
use for their walls.
EndText
);
    set( "night long", @EndText
This is a bending in the huge road. The tall walls block out most
of the light from the stars. To the north you barely see the signs
of something that looks like a guard post. Dull lights can be seen
far off to the west.
EndText
);
    add_item("boulders", "Huge pieces of stones just seem to lie around
here.");
    set_exits( ({ ROOMS_PATH+"quarry_entrance",
ROOMS_PATH+"quarry_guard_post" }), ({ "west", "north" }) );
}

