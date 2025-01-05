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
This is the south side of DayBreak Castle, which was once heavily populated. Here and there you see dead rats, decayed and foaming around the mouth, they litter the pathway like a disgusting layer of carpet. 

	
	
EndText);

    set( "night long", @EndText
This is the south side of DayBreak Castle, which was once heavily populated. Here and there you see dead rats, decayed and foaming around the mouth, they litter the pathway like a disgusting layer of carpet. 

EndText);

//add_exit(PATH+"r123.c", "north");
add_exit(PATH+"r126.c", "east");
//add_exit(PATH+"r125.c", "southwest");
add_exit(PATH+"r103.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
