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
This room appears to be a torture room with hooks and chain along the wall. you can smell the rotten flesh from bodies laying against the floor that appeared had died a few days ago. You notice furniture in the back corner which appeared it once belonged to someone important. you might find something interesting at the desk that might lead to a secret room.
 
%^COLOR28%^The air is putrid, with the smell of dead flesh.%^RESET%^

	
	
EndText);

    set( "night long", @EndText
This room appears to be a torture room with hooks and chain along the wall. you can smell the rotten flesh from bodies laying against the floor that appeared had died a few days ago. You notice furniture in the back corner which appeared it once belonged to someone important. you might find something interesting at the desk that might lead to a secret room.
 
%^COLOR28%^The air is putrid, with the smell of dead flesh.%^RESET%^

	
EndText);

//add_exit(PATH+"r89.c", "north");
//add_exit(PATH+"r34.c", "east");
add_exit(PATH+"r122.c", "southwest");
//add_exit(PATH+"r35.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
