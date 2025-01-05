#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 1);
    set( "short", "The huge quarry." );
    set( "day long", @EndText
Everywhere people are working and shouting at each
other in different languages. The huge greater orcs
with their whips shout commands to the smaller slaves
and an occasional whiplash can be heard through the 
noise of the work. This part of the quarry is open
in all directions.
EndText
);
    set( "night long", @EndText
You are walking around under the dim light of the
stars. It is very quiet and peaceful here, not at
all like this place is during the day.
EndText
);
    set_exits( ({ ROOMS_PATH+"q_13", ROOMS_PATH+"q_24", ROOMS_PATH+"q_22",
ROOMS_PATH+"q_33" }), ({ "west", "south", "north", "east" }) );
}

