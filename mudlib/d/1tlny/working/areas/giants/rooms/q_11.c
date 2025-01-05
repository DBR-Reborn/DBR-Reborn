#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "The huge quarry." );
    set( "day long", @EndText
You are standing in the northern parts of the storm-
giant quarry. Further north and west the quarry ends,
it seems like the quality of the rock was not good
enough in those directions, for work has ended there.
The wall to the east is being worked on though, you
can see that clearly, even if there are no workers here
right now.
EndText
);
    set( "night long", @EndText
The ground in this quarry seems almost perfectly
horizontal. Even though it is not extremly dark,
you can not see where this large area ends.
EndText
);
    add_item("wall", "The eastern wall is being worked on. It is not as flat as the other walls you have seen around here.");
    set_exits( ({ ROOMS_PATH+"q_01", ROOMS_PATH+"q_10",
ROOMS_PATH+"q_12" }), ({ "west", "north", "south" }) );
}

