#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 2);
    set( "short", "%^RED%^Eros Avenue%^RESET%^" );
    set( "long", @EndText
EndText
);
    set_exits( ({ PATH+"eros4.c", PATH+"eros2.c" }), ({ "south", "north" }) );
}
