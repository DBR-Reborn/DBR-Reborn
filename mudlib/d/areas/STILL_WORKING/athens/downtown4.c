#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "%^YELLOW%^Downtown Atharnas%^RESET%^" );
    set( "day long", @EndText
EndText
);
    set( "night long", @EndText
    At night the streets are almost empty except for
near the inn's and taverns where a few travvlers
still stand, talking and drinking together. Streetlamps
lined around the clock tower and leading down the
streets light the night. The large clock tower
dominates your view, standing in the center of
the square.
EndText
);
    set_exits( ({ PATH+"downtown5.c", PATH+"downtown3.c" }), ({ "west", "south" }) );
}
