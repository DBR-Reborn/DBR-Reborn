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

    You are standing in the arch-way doorway. You can hear sounds of monsters echoing from inside.
	
	%^BOLD%^WHITE%^(15-25+ Level)%^RESET%^
EndText);

    set( "night long", @EndText
It is dark and gloomy here.

    You are standing in the arch-way doorway. You can hear sounds of screams echoing from inside.
	
	%^BOLD%^WHITE%^(15-25+ Level)%^RESET%^
EndText);

add_exit(PATH+"r4.c", "south");
add_exit(PATH+"r60.c", "enter");
//add_exit(PATH+"r4.c", "east");
//add_exit(PATH+"r5.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
