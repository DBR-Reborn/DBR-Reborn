#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 2);
    set( "short", "Inside the Clock Tower" );
    set( "long", @EndText
EndText
);
    set_exits( ({ PATH+"clock2.c", PATH+"clock4.c" }), ({ "down", "up" }) );
}
