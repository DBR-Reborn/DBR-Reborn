#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void create()
{
	   ::reset();
    if (!present("ghost soldier")){
      	new(MON+"ghost soldier.c")->move(this_object());
		new(MON+"ghost soldier.c")->move(this_object());
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
You are standing in a soldiers hall that leads deeper southwest into the
castle where you hear echo's of military marching and soldiers whispering
to one another. As you continue to stand in the room you begin to see blobs
of mist floating around you.
	
	
EndText);

    set( "night long", @EndText
You are standing in a soldiers hall that leads deeper southwest into the
castle where you hear echo's of military marching and soldiers whispering
to one another. As you continue to stand in the room you begin to see blobs
of mist floating around you.
EndText);

//add_exit(PATH+"r149.c", "north");
add_exit(PATH+"r163.c", "northeast");
//add_exit(PATH+"r151.c", "south");
add_exit(PATH+"r166.c", "southwest");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
