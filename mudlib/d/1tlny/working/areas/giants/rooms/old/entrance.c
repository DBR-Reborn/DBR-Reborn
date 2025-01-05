#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Entrance to village." );
    set( "day long", @EndText
As you enter the village you feel very small when staring
at the HUGE stone walls towering around you. Bulking guards
stand infront of you, their faces and incredible size tells
you these guys are not to be messed with. To the east a small
road, leading into the village, can be seen.
EndText
);
    set( "night long", @EndText
As you enter the village you feel very small when staring
at the HUGE stone walls towering around you. Bulking guards
stand infront of you, their faces and incredible size tells
you these guys are not to be messed with. To the east a small
road, leading into the village, can be seen.
EndText
);
    add_item("walls","These impressive walls seem to tower no less
than 30 feet above you.");
set_exits( ({ ROOMS_PATH+"road" }), ({ "east" }) );
}

