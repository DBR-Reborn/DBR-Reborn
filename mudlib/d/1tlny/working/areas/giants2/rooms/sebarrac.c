#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 1);
    set( "short", "Southern Guard Barrack." );
    set( "day long", @EndText
You seem to have entered the sleeping quarters of these barracks.
In the back of the room you see some huge beds that appears to be 
made of solid stone. At the southern wall hangs a painting and
there is a open door to the west.
EndText
);
    set( "night long", @EndText
You seem to have entered the sleeping quarters of these barracks.
Not much can be seen in this darkness but in the back of the room
you notice some beds. However the size of these beds tells you they
aren't meant for you. Besides they seem to be made of solid stone.
At the southern wall hangs a painting and there is a open door to the
west.
EndText
); 
    add_item("wall","This impressive wall seem to tower no less
than 30 feet above you.");
    add_item("walls","These impressive walls seem to tower no less
than 30 feet above you.");    add_item("painting","It seems to be a storm-giant wrestling a mammoth.
WOW!");
    add_item("bed","A huge bed, bigger than any you have ever seen
before.");
    add_item("beds","Three huge beds, they are bigger than any beds you
have ever seen before!");

    set_exits( ({ ROOMS_PATH+"sbarrack" }), ({ "west" }) );
}



