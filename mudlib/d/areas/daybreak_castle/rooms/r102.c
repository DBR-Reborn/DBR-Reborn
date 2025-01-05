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
your standng at a "T" intersection and this is where you have to tell yourself if you are able to survive moving forward.

you smell %^COLOR130%^BURNING%^RESET%^ flesh to the south	
	
you see %^COLOR230%^SHADOWS%^RESET%^ blocking out the light from the torches to the east		
	
EndText);

    set( "night long", @EndText
your standng at a "T" intersection and this is where you have to tell yourself if you are able to survive moving forward.

you smell %^COLOR130%^BURNING%^RESET%^ flesh to the south

you see %^COLOR230%^SHADOWS%^RESET%^ blocking out the light from the torches to the east	

EndText);

//add_exit(PATH+"r89.c", "north");
add_exit(PATH+"r121.c", "east");
add_exit(PATH+"r41.c", "south");
add_exit(PATH+"r91.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
