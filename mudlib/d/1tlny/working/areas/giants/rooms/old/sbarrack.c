#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Southern Guard Barrack." );
    set( "day long", @EndText
This room is lit up by a lantern hanging from the southern wall. In this
brightness strange marks can be seen in the walls. Someone seems
to have made em using nothing but their bare hands! Perhaps it was
one of the guards who is staring at you angrily? To the east is an open
door leading into another room and to the north you see a road.
EndText
);
    set( "night long", @EndText
This room is lit up by a lantern hanging from the southern wall. In this
brightness strange marks can be seen in the walls. Someone seems
to have made em using nothing but their bare hands! Perhaps it was
one of the guards who is staring at you angrily? To the east is an open
door leading into another room and to the north you see a road.
EndText
);
    set_exits( ({ ROOMS_PATH+"road2", ROOMS_PATH+"sebarrac" }), ({ "north", "east" }) );
}


