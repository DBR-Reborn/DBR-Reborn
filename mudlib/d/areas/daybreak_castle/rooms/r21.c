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
    if(!present("moth")) {
        new(MON+"moth.c")->move(this_object());
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
This walls around you are filled with cracks and chipped paint. The cieling
is falling apart and has alot of holes in it. There seems to be just enough
light coming throw the holes in the ceiling to light up the room. The
passage way opens up into a mid sized room which you see giat rat prints
leading north and south. 
	
	
EndText);

    set( "night long", @EndText
This walls around you are filled with cracks and chipped paint. The cieling
is falling apart and has alot of holes in it. There seems to be just enough
light coming throw the holes in the ceiling to light up the room. The
passage way opens up into a mid sized room which you see giat rat prints
leading north and south. 
EndText);

add_exit(PATH+"r19.c", "north");
add_exit(PATH+"r23.c", "south");
//add_exit(PATH+"r4.c", "east");
//add_exit(PATH+"r5.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
