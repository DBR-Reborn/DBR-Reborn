#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 2);
    set( "short", "The southern gate." );
    set( "day long", @EndText
    You stand just inside the gate to Atharnas. A
couple of members of the Canther milita stand around
guarding the gates. You chuckle to yourself as you
picture them fighting off an ivasion of any sort.
EndText
);
    set( "night long", @EndText
    You enter the small town of Atharnas, greeted by
the sight of several of the members of the Canther
milita nodding sleepily sitting at their desk inside
the small building next to the gate.
EndText
);
    set_exits( ({ PATH+"ga7.c", }), ({ "south" }) );
}
