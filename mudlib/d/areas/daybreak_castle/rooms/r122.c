#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void reset() {
        ::reset();
if (!present("castle warrior")) 
new(MON+"castlewarrior.c")->move(this_object());

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
This part of the road has some mud along the floor that hasn't been destroyed as you would be the first to step onto it. Some skeletons are scattered up against the wall as if they had died where they were positioned. While blood and mud are splattered everywhere you feel the need to move quickly forward or you will be one of the skeletons you see.
 
%^ORANGE%^There is the smell of decay in the air coming from southeast.%^RESET%^

%^COLOR43%^You hear some muffled screams to the northeast.%^RESET%^
	
	
EndText);

    set( "night long", @EndText
This part of the road has some mud along the floor that hasn't been destroyed as you would be the first to step onto it. Some skeletons are scattered up against the wall as if they had died where they were positioned. While blood and mud are splattered everywhere you feel the need to move quickly forward or you will be one of the skeletons you see.
 
%^ORANGE%^There is the smell of decay in the air coming from southeast.%^RESET%^

%^COLOR43%^You hear some muffled screams to the northeast.%^RESET%^

EndText);

add_exit(PATH+"r47.c", "northeast");
add_exit(PATH+"r123.c", "southeast");
//add_exit(PATH+"r53.c", "south");
add_exit(PATH+"r121.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
