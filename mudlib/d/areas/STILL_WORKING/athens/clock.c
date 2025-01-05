#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3 );
    set_property( "night light", 2);
    set( "short", "%^YELLOW%^At the Foot of the Clock Tower" );
    set( "long", @EndText
    Standing at the base of the large clock tower you feel
quite small, and the hobbits wandering around look even
smaller. There is a green lawn around the tower with stone
sidewalk leading to the door entering the tower. There are
benches placed around the lawn facing outwards towards the
shops lining the square.
EndText
);
    set_exits( ({ PATH+"downtown1.c", PATH+"downtown7.c", PATH+"downtown5.c", PATH+"downtown3.c", PATH+"clock2.c" }), ({ "south", "west", "north", "east", "tower" }) );
set_smell("default", "It smells like freshly cut grass.");
}
