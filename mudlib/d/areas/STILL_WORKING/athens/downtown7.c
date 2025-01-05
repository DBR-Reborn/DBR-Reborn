#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 2);
    set( "short", "%^YELLOW%^Downtown Atharnas%^RESET%^" );
    set( "long", @EndText
EndText
);
    set_exits( ({ PATH+"downtown8", PATH+"downtown6", PATH+"spect1.c", PATH+"clock.c" }), ({ "south", "north", "west", "east" }) );
}
