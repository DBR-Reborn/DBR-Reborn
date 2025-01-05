#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
set_property("light", 3);
    set_property( "night light", 2);
    set( "short", "Gondorian Avenue" );
    set( "day long", @EndText
     The streets are lined with house after house, tightly
packed next to each other. A small halfling child peers
out one of the windows at you as you pass. Smoke rises
into the air from some of the buildings.
EndText
);
    set( "night long", @EndText
     The streets are lined with house after house, tightly
packed next to each other. You can see light from a few of
the windows on the houses along the street, but most people
seem to be sleeping.
EndText
);

    set_exits( ({ PATH+"ga3.c", PATH+"ga5.c" }), ({ "south", "north"
}) );
}

