#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    set_property( "light", 2);
    set( "short", "%^YELLOW%^Downtown Atharnas%^RESET%^" );
    set( "long", @EndText
EndText
);
    set_exits( ({ PATH+"downtown6.c", PATH+"downtown4.c", PATH+"ga6.c", PATH+"clock.c" }), ({ "west", "east", "north", "south" }) );

}
