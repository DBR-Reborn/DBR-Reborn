#include <std.h>
#include "../a1.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 1);
    set( "short", "The southern entrance." );
    set( "day long", @EndText
    You standing just inside the quary to the dwarven mine.
    0   
    |   
    @
EndText
);
    set( "night long", @EndText
    You standing just inside the quarry to the dwarven mine.
    0   
    |   
    @
EndText
);
    set_exits( ({ PATH+"r1.c", }), ({ "north" }) );
add_exit("/d/damned/virtual/room_8_22.world", "leave");
}

