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
    set( "short", "Under Construction." );
    set( "day long", @EndText
this area if closed off for construction.
	
	
EndText);

    set( "night long", @EndText
this area if closed off for construction.
EndText);

add_exit(PATH+"r4.c", "out");
//add_exit(PATH+"r65.c", "east");
//add_exit(PATH+"r37.c", "south");
//add_exit(PATH+"r49.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
