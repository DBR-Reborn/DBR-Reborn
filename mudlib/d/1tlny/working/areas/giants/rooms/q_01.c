#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Northwest corner of the quarry.");
    set( "day long", @EndText
You stand in what seems to be the northwest corner
of this huge place. This part of the quarry is relatively
peaceful and it seems as if they have stopped expanding
in this direction, perhaps the rock wasnt of good enough
quality further to the northwest.
EndText
);
    set( "night long", @EndText
You stand in what seems to be the northwest corner
of this huge place. Looking south and east the floor
stretches far into the night. Everything is quiet and
peaceful.
EndText
);
    set_exits( ({ ROOMS_PATH+"q_11", ROOMS_PATH+"q_02" }), ({ "east", "south" }) );
}

