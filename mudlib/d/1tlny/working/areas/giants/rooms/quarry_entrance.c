#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 1);
    set( "short", "Entrance to quarry." );
    set( "day long", @EndText
This is the entrance to the enormous storm-giant quarry. The
road seems to lead slightly downwards directly into a huge pit
stretching hundreds, maybe thousands of feet in all directions.
You hear a lot of noise from the huge boulders being chopped off
the enormous cliffs and dragged across the rocky ground. The walls
of the pit stretch towards the sky at least fifty feet above you,
outlining a huge road leading east. To the west you see the
marketplace.
EndText
);
    set( "night long", @EndText
The road leads slightly downwards into a huge black pit that
seems to stretch forever out into the darkness. The enourmosity
together with the darkness makes you feel as if you were in some
sort of endless void. A shimmering, soft light comes from the
marketplace west of here.
EndText
);
    set_exits( ({ ROOMS_PATH+"quarry_road"}), ({ "east" }) );
}

