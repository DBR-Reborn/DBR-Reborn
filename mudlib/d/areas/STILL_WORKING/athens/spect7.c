#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 2);
    set( "short", "%^CYAN%^Spectral Lane%^RESET%^" );
    set( "long", @EndText
EndText
);
    set_exits( ({ PATH+"spect6.c", PATH+"spect8.c" }), ({ "west", "east" }) );
}
