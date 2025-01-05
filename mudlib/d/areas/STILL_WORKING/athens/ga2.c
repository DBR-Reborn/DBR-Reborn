#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Gondorian Avenue" );
    set( "day long", @EndText
    This is the southern end of Gondorian Avenue.
There is only little activity here, a few of the
civilians  run around doing all sorts of chores
and people from the Canther militia are posted 
to the south.
EndText
);
    set( "night long", @EndText
    This is the southern end of Gondorian Avenue.
Most of the street looks empty from here, not many
of the townfolk seem to come out at night.
EndText
);

    set_exits( ({ PATH+"ga3.c", PATH+"a_enter.c" }), ({ "north", "south" })
);
}

