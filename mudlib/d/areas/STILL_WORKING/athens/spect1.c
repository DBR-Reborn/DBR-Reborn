#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Spectral Lane" );
    set( "day long", @EndText
    You stand on Spectral Lane, just inside the western
gate. Further east is a huge clocktower, which seems to
be the illuminated center of this town. There are many
townfolk moving through here, from their homes towards
the surroundings of the clock, which seems to function
as a marketplace.
EndText
);
    set( "night long", @EndText
    You stand on Spectral Lane, just inside the western
gate. Further east is a huge clocktower, which seems to
be the illuminated center of this town. A few people are
still out walking in the night, but most seem to be heading
towards their homes after a long busy day at the market.
EndText
);

    set_exits( ({ PATH+"spect2.c", PATH+"downtown7.c", PATH+"addspect1.c",
 PATH+"gate4.c" }), ({ "north", "east", "south", "west" }) );
}

