#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void create()
{
	
	   ::reset();
    if (!present("rat")){
        new(MON+"rat.c")->move(this_object());
	}
	   ::reset();
    if(!present("turtle")) {
        new(MON+"turtle.c")->move(this_object());
		new(MON+"turtle.c")->move(this_object());
    }
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
The hall wall continues to the southwest, east and to the north. On the ground you notice some very large bat fecus but dont look up.  
	
	
EndText);

    set( "night long", @EndText
The hall wall continues to the southwest, east and to the north. On the ground you notice some very large bat fecus but dont look up.  
EndText);

add_exit(PATH+"r21.c", "north");
add_exit(PATH+"r131.c", "southwest");
add_exit(PATH+"r24.c", "east");
//add_exit(PATH+"r5.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
