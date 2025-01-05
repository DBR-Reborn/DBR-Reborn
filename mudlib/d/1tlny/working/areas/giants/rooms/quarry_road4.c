#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "End of Quarry road." );
    set( "day long", @EndText
You stand at the end of Quarry road. The view when you
overlook the quarry to the east is magnificent, every-
thing is so big! Everywhere sweating workers with their
slave-drivers can be seen. To the west the road runs
slightly upwards towards the centre of the village.
EndText
);
    set( "night long", @EndText
You stand at the end of Quarry road. Damp and dark the
road moves between the huge walls to the west, while to
the east an enormous open area expands.
EndText
);
    set_exits( ({ ROOMS_PATH+"quarry_road3", ROOMS_PATH+"q_03"
}), ({ "west", "east" }) );
}

