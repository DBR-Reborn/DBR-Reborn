#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 1);
    set_property("indoors", 1);

    set( "short", "The southern entrance." );
    set( "day long", @EndText
This is the part of the road that connects with the Crossroads between evil
and even more evil. All the hallways here seem to be the most badly
damaged, cracked, falling apart as you suspect you might not make it out
alive but decides to keep moving forward. DayBreak Castle use to seem to be
a palace one day in the past except for a few hidden treasures that were
hidden before the raid.
 
	
	
EndText);

    set( "night long", @EndTextThis is the part of the road that connects with the Crossroads between evil
and even more evil. All the hallways here seem to be the most badly
damaged, cracked, falling apart as you suspect you might not make it out
alive but decides to keep moving forward. DayBreak Castle use to seem to be
a palace one day in the past except for a few hidden treasures that were
hidden before the raid.

EndText);

add_exit(PATH+"r141.c", "north");
add_exit(PATH+"r129.c", "east");
add_exit(PATH+"r42.c", "south");
add_exit(PATH+"r128.c", "west");


}
