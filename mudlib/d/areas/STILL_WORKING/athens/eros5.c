#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 2);
    set( "short", "%^RED%^The Corner of Eros and Dethern%^RESET%^" );
    set( "long", @EndText
EndText
);
    set_exits( ({ PATH+"dr7.c", PATH+"eros4.c", PATH+"eros6.c" }), ({ "south", "east", "west" }) );
}
