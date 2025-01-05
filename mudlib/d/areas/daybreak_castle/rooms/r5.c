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
It is dark and gloomy here.

    You are standing in the arched doorway. You can hear sounds of monsters echoing from inside.
	
	%^WHITE%^(1-10+ Level)%^RESET%^
EndText);

    set( "night long", @EndText
It is dark and gloomy here.

    You are standing in the arched doorway. You can hear sounds of monsters echoing from inside.
	
	%^WHITE%^(1-10+ Level)%^RESET%^
EndText);

add_exit(PATH+"r4.c", "northeast");
add_exit(PATH+"r14.c", "enter");
//add_exit(PATH+"r2.c", "east");
//add_exit(PATH+"r5.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
