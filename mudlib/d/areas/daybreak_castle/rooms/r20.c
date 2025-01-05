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
		new(MON+"crawler.c")->move(this_object());
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
You are standing in a hall where the floor is littered with bath droppings.
The odor is so strong you sense safety is not far. The room opens up to the
west, southeast and to the north.

%^YELLOW%^Something Creepy is crawling around the floor.%^RESET%^
	
	
EndText);

    set( "night long", @EndText
You are standing in a hall where the floor is littered with bath droppings.
The odor is so strong you sense safety is not far. The room opens up to the
west, southeast and to the north.

%^YELLOW%^Something Creepy is crawling around the floor.%^RESET%^

EndText);

add_exit(PATH+"r18.c", "north");
//add_exit(PATH+"r1.c", "south");
add_exit(PATH+"r134.c", "southeast");
add_exit(PATH+"r22.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
