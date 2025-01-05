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
Overwhelmed by the size of this place, you find yourself
staring up at the walls now towering some 70 feet almost
straight up towards the sky. You get slightly dizzy from
looking up and decide to keep looking straight forward
instead. The road moves in a straight line east towards
a gigantic open area. To the west it seems to bend south-
wards.
EndText
);
    set( "night long", @EndText
The darkness surrounding you is profound. The light from
the stars makes huge shadows appear on the walls around
you. The darkness continues west along with the road, but
looking east it seems slightly brighter, as if there was
a clearing of some sort there.
EndText
);
    set_exits( ({ ROOMS_PATH+"quarry_road2", ROOMS_PATH+"quarry_road4"
}), ({ "west", "east" }) );
}

