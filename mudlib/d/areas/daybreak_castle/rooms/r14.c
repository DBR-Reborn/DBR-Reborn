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

You are standing in a hall that only leads into two directions which may end with hidden treasure. The stories you have heard about this area may or may not be true but you can see giant rat tracks to the west and hear disanbody voices echoing from all directions. you can feel a small sensation of the ceiling and walls cracking from old age.
	
%^YELLOW%^You begin to smell rotting flesh and faint foot steps not too far ahead.%^RESET%^
EndText);

    set( "night long", @EndText
There is torches on the walls providing light.

You are standing in a hall that only leads into two directions which may end with hidden treasure. The stories you have heard about this area may or may not be true but you can see giant rat tracks to the west and hear disanbody voices echoing from all directions. you can feel a small sensation of the ceiling and walls cracking from old age.
	
%^YELLOW%^You begin to smell rotting flesh and faint foot steps not too far ahead.%^RESET%^
EndText);

add_exit(PATH+"r5.c", "out");
add_exit(PATH+"r16.c", "south");
//add_exit(PATH+"r4.c", "east");
add_exit(PATH+"r13.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
