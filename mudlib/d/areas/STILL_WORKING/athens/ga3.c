#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property("light", 3);
    set_property("night light", 2);
    set("short", "Gondorian and Dethern" );
    set("day long", @EndText
    This is the intersection of Gondorian Avenue,
leading from the southern gate towards the center
of town and Dethern Road. A few villagers stroll
around and some children seem to play some game
where they chase eachother back and forth.
EndText
);
    set("night long", @EndText
    This is the intersection of Gondorian Avenue,
leading from the southern gate towards the center
of town and Dethern Road. The streets are just
about empty at night.
EndText
);

     set_exits( ({ PATH+"ga2.c", PATH+"ga4.c", PATH+"dr2.c", PATH+"dr3.c"
}), ({ "south", "north", "west", "east" }) );
}

