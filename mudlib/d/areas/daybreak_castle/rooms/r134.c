#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void create()
{
	
	   ::reset();
    if (!present("crawler")){
       	new(MON+"crawler.c")->move(this_object());
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
You are standing in a hall that leads deeper into the castle where the floor is littered with streaks. The odor is so strong you begin to get dizzy from the smell. The room opens up to the northwest, west and south.

%^YELLOW%^Something Creepy is crawling around the floor.%^RESET%^
	
	
EndText);

    set( "night long", @EndText
You are standing in a hall that leads deeper into the castle where the floor is littered with streaks. The odor is so strong you begin to get dizzy from the smell. The room opens up to the northwest, west and south.

%^YELLOW%^Something Creepy is crawling around the floor.%^RESET%^
EndText);

add_exit(PATH+"r20.c", "northwest");
//add_exit(PATH+"r149.c", "east");
add_exit(PATH+"r163.c", "south");
add_exit(PATH+"r32.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
