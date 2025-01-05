#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void reset() {
        ::reset();
if (!present("bat")) 
new(MON+"bat.c")->move(this_object());
new(MON+"bat.c")->move(this_object());
new(MON+"moth.c")->move(this_object());
new(MON+"moth.c")->move(this_object());
}


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
The hall wall continues to the west, east and to the south. On the ground you notice some very large bat fecus but dont look up.  
                
	
	
EndText);

    set( "night long", @EndText
The hall wall continues to the west, east and to the south. On the ground you notice some very large bat fecus but dont look up.  
EndText);

//add_exit(PATH+"r123.c", "north");
add_exit(PATH+"r33.c", "east");
add_exit(PATH+"r162.c", "south");
add_exit(PATH+"r131.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
