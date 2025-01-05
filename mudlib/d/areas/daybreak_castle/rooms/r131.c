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
The hall wall continues to the northeast and to the east. On the ground
you notice some very large bat fecus but dont look up.  
	
	
EndText);

    set( "night long", @EndText
The hall wall continues to the northeast and to the east. On the ground
you notice some very large bat fecus but dont look up.  
EndText);

add_exit(PATH+"r23.c", "northeast");
add_exit(PATH+"r132.c", "east");
//add_exit(PATH+"r129.c", "southwest");
//add_exit(PATH+"r109.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
