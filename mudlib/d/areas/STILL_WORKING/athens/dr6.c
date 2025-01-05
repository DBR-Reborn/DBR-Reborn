#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 2);
    set( "short", "%^RED%^Dethern Road%^RESET%^" );
    set( "long", @EndText
EndText
);
     set_exits( ({ PATH+"dr5.c", PATH+"dr7.c" }), ({ "south", "north" }) );
}
