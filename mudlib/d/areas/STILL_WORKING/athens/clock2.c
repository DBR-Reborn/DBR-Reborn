#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 2);
    set( "short", "Inside the Clock Tower" );
    set( "long", @EndText
    You stand at the foot of a set of winding stairs which
lead up past all the large gears which turn the hands
of the large clock. A small hobbit workman sits in the
corner taking a little snooze.
EndText
);
    set_exits( ({ PATH+"clock.c", PATH+"clock3.c" }), ({ "out", "up" }) );
}
