#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;


void create()
{
	
	   ::reset();
    if (!present("bat")){
        new(MON+"bat.c")->move(this_object());
		new(MON+"bat.c")->move(this_object());
		new(MON+"bat.c")->move(this_object());
		new(MON+"bat.c")->move(this_object());
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
You are standing in a small arch-way. The rough walls are smoothed with cracks and chunks missing. There is a thick layer of dust and debris on the floor which shows this room has not been walked through in awhile. hall wall continues to the west and east.
	
EndText);

    set( "night long", @EndText
You are standing in a small arch-way. The rough walls are smoothed with cracks and chunks missing. There is a thick layer of dust and debris on the floor which shows this room has not been walked through in awhile. hall wall continues to the west and east.

EndText);

//add_exit(PATH+"r3.c", "north");
//add_exit(PATH+"r1.c", "south");
add_exit(PATH+"r22.c", "east");
add_exit(PATH+"r23.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
