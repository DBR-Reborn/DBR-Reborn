#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void reset() {
        ::reset();
if (!present("drunk_ghost")) 
new(MON+"drunk_ghost.c")->move(this_object());
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
The walls around you look like there about to topple down apon you. In these halls you might tend to spot of a drunken ghost who had too much to drink. The road continues east and south.
	
	
EndText);

    set( "night long", @EndText
The walls around you look like there about to topple down apon you. In these halls you might tend to spot of a drunken ghost who had too much to drink. The road continues east and south.
EndText);

//add_exit(PATH+"r3.c", "north");
add_exit(PATH+"r19.c", "south");
add_exit(PATH+"r15.c", "east");
//add_exit(PATH+"r5.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
