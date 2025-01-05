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
This is a pathway through the DayBreak castle, usually populated by many people, now deserted. Dead rodents and filth splatter all over the floor. 

%^COLOR142%^You can only hear the sound of wood crakling in the distance.%^RESET%^
	
	
EndText);

    set( "night long", @EndText
This is a pathway through the DayBreak castle, usually populated by many people, now deserted. Dead rodents and filth splatter all over the floor. 

%^COLOR142%^You can only hear the sound of wood crakling in the distance.%^RESET%^
	
EndText);

add_exit(PATH+"r122.c", "northwest");
//add_exit(PATH+"r180.c", "east");
add_exit(PATH+"r124.c", "south");
//add_exit(PATH+"r109.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
