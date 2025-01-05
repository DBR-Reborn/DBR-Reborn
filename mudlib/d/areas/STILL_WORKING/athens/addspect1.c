#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Spectral Lane" );
    set( "day long", @EndText
    The houses here on Spectral Lane seem to
belong to the wealthier class of the halflings.
The houses are slightly bigger here than in the
rest of the town.
EndText
);
    set( "night long", @EndText
    This part of town seems quiet at night.
A few of the windows on the houses along the
streets are lit, but the majority of the
residents here seem to be sleeping.
EndText
);
    set_exits( ({ PATH+"spect1.c", PATH+"addspect2.c" }), ({ "north",
"south" }) );
}

