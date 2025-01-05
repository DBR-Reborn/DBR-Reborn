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
There is torches on the walls providing light.

    You are standing in a pathway that only leads north & south.
	
You begin to smell rotting flesh and faint foot steps not too far ahead.
EndText);

    set( "night long", @EndText
There is torches on the walls providing light.

    You are standing in a pathway that only leads north & south.
	
You begin to smell rotting flesh and faint foot steps not too far ahead.
EndText);

add_exit(PATH+"r5.c", "out");
add_exit(PATH+"r13.c", "north");
add_exit(PATH+"r14.c", "south");
//add_exit(PATH+"r5.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
