#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Downtown Atharnas" );
    set( "day long", @EndText
    You are quite close to the large clock tower of Atharnas,
and from here can even see what time it has. A few people
of other races can be seen here, but most everyone is a
halfling, and those who are not seem quite out of place.
EndText
);
    set( "night long", @EndText
    At night the streets are almost empty except for
near the inn's and taverns where a few travellers still
stand, talking and drinking together. Streetlamps lined
around the clock tower and leading down the streets light
the night. The large clock tower dominates your view,
standing in the center of the square.
EndText
);
set_exits( ({ PATH+"ga5.c", PATH+"clock.c", PATH+"downtown2.c",
PATH+"downtown8.c" }), ({ "south", "north", "east", "west" }) );
}

