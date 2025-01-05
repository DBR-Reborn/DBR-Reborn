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

    //set_property("no attack", 1); 
    //set_property("no cast", 1);
    //set_property("no scry", 1);
    //set_property("no teleport", 1);
    //set_property("no summon", 1);
    set( "short", "The southern entrance." );
    set( "day long", @EndText
This is the part of the road that connects with the Crossroads between evil and even more evil. All the hallways here seem to be the most badly damaged, cracked, falling apart as you suspect you might not make it out alive but decides to keep moving forward. DayBreak Castle use to seem to be a palace one day in the past except for a few hidden treasures that were hidden before the raid.
	
	
EndText);

    set( "night long", @EndText
This is the part of the road that connects with the Crossroads between evil and even more evil. All the hallways here seem to be the most badly damaged, cracked, falling apart as you suspect you might not make it out alive but decides to keep moving forward. DayBreak Castle use to seem to be a palace one day in the past except for a few hidden treasures that were hidden before the raid.
EndText);

add_exit(PATH+"r102.c", "north");
//add_exit(PATH+"r34.c", "east");
add_exit(PATH+"r38.c", "south");
//add_exit(PATH+"r35.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
