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
    set_exits( ({ PATH+"downtown5.c", PATH+"downtown7.c" }), ({ "east", "south" }) );
}
