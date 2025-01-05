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
Walking north along the walls you can see claw marks as if someone had been dragged against their will. further down the hall you notice something far off in the distance, you can't seem to make it out but do notice movement. you sense danger ahead but still compell to keep moving forward.

	
EndText);

    set( "night long", @EndText
Walking north along the walls you can see claw marks as if someone had been dragged against their will. further down the hall you notice something far off in the distance, you can't seem to make it out but do notice movement. you sense danger ahead but still compell to keep moving forward.


EndText);

add_exit(PATH+"r89.c", "north");
add_exit(PATH+"r45.c", "east");
add_exit(PATH+"r37.c", "south");
//add_exit(PATH+"r35.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
