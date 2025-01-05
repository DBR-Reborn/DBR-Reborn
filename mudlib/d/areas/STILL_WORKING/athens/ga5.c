#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
set_property("light", 4);
    set_property( "night light", 2);
    set( "short", "Approaching the Clock Tower" );
    set( "day long", @EndText
    As you approach the downtown area of Atharnas, the large
clock tower in the middle of the square is growing before
you. Halflings of varied sizes wander through the streets
eyeing you as if they had never seen a stranger before.
EndText
);
    set( "night long", @EndText
    As you approach the downtown area of Atharnas, the large
clock tower in the middle of the square is growing before
you. There are a few people still wandering around here even
though it is night. Some sing in shrill voices, it seems as
they are somewhat drunk.
EndText
);

    set_exits( ({ PATH+"ga4.c", PATH+"downtown1.c" }), ({ "south", "north"
}) );
}

