#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 2);
    set( "short", "%^YELLOW%^Gondorian and Spectral%^RESET%^" );
    set( "long", @EndText
EndText
);
    set_exits( ({ PATH+"spect5.c", PATH+"spect6.c", PATH+"ga6.c", PATH+"gate3.c" }), ({ "west", "east", "south", "north" }) );
}
