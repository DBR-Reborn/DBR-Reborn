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
you entered into this room and see castle keepers scrubbing the floors and walls, washing away blood stains from what appeared to be recent killings. you should not underestimate these works as contact castle cleaning have increased thier strenght.

%^COLOR123%^Mops & Buckets are scattered across the room%^RESET%^  
	
	
EndText);

    set( "night long", @EndText
you entered into this room and see castle keepers scrubbing the floors and walls, washing away blood stains from what appeared to be recent killings. you should not underestimate these works as contact castle cleaning have increased thier strenght.

%^COLOR123%^Mops & Buckets are scattered across the room%^RESET%^  
EndText);

//add_exit(PATH+"r89.c", "north");
add_exit(PATH+"r102.c", "east");
//add_exit(PATH+"r37.c", "south");
add_exit(PATH+"r90.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
