#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 2);
    set( "short", "%^RED%^The Corner of Eros and Spectral%^RESET%^" );
    set( "long", @EndText
EndText
);
    set_exits( ({ PATH+"eros2.c", PATH+"spect8.c" }), ({ "south", "west" }) );
}
