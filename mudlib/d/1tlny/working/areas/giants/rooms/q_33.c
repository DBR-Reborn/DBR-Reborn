#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Eastern parts of the quarry." );
    set( "day long", @EndText
You are standing by the huge eastern wall marking
out the end of this quarry. To the west the central
parts of this place opens up and to the south there
is a large passageway between the rock walls leading
quite some way further.
EndText
);
    set( "night long", @EndText
This place is very quiet and peaceful at night and
none of the alarms of the daily work can be heard.
The only thing you hear are the noise of an occasional
cricket.
EndText
);
    set_exits( ({ ROOMS_PATH+"q_23", ROOMS_PATH+"q_34" }), ({ "west", "south" }) );
}

