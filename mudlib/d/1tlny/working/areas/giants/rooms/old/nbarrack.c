#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Northern Guard Barrack." );
    set( "day long", @EndText
This is a guard barrack. Here the guards who are not on duty
rests. Unlike most guardposts you have seen this place seems
to be in order. The Storm-Giants obviously take their duties
seriously. In the middle of the room a table with three chairs
can be seen. The floor is is covered with dust from the somewhat
cracked walls surrounding the room. To the south a road can be seen.
EndText
);
    set( "night long", @EndText
This is a guard barrack. Here the guards who are not on duty
rests. Unlike most guardposts you have seen this place seems
to be in order. The Storm-Giants obviously take their duties
seriously. In the middle of the room a table with three chairs
can be seen. The floor is is covered with dust from the somewhat
cracked walls surrounding the room. To the south a road can be seen.
EndText
);
    set_exits( ({ ROOMS_PATH+"road2" }), ({ "south" }) );
}


