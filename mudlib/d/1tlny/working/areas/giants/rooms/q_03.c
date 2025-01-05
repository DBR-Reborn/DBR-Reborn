#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "The huge quarry." );
    set( "day long", @EndText
The ground in this quarry seems almost perfectly
horizontal in opposition to the slightly sloping Quarry
Road leading west of here. Far to the east you see what
seems to be the eastern end of this place, but estimating
the distance there is impossible, many hundreds of feet
at least. Even though the quarry is in no perfect geometrical
shape, everywhere the walls of it are perfectly vertical,
towering towards the sky.
EndText
);
    set( "night long", @EndText
The ground in this quarry seems almost perfectly
horizontal in opposite to the slightly sloping Quarry
road leading west of here. Even though it is not extremly
dark, you can not see where this large area ends.
EndText
);
    set_exits( ({ ROOMS_PATH+"quarry_road4", ROOMS_PATH+"q_13",
ROOMS_PATH+"q_04", ROOMS_PATH+"q_02" }), ({ "west", "east", "south",
"north" }) );
}

