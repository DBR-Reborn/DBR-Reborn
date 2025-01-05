#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 2);
    set( "short", "%^YELLOW%^Gondorian Avenue%^RESET%^" );
    set( "long", @EndText
EndText
);
   set_exits( ({ PATH+"downtown5.c", PATH+"ga7.c" }), ({ "south", "north" }) );
}
