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
You are standing in a pathway that only leads ??????
	
	
EndText);

    set( "night long", @EndText
You are standing in a pathway that only leads ????????.
EndText);

add_exit(PATH+"r182.c", "north");
add_exit(PATH+"r184.c", "east");
//add_exit(PATH+"r151.c", "south");
//add_exit(PATH+"r114.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
