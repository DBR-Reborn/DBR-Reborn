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
your walking through a dark pathway that looks to be heavily traveled. you can feel cob webs getting in your way and you begin to feel a damp sensation coming over you. you feel the urge to ove forward.

%^COLOR220%^Well lit torches line the room.%^RESET%^
EndText);

    set( "night long", @EndText
your walking through a dark pathway that looks to be heavily traveled. you can feel cob webs getting in your way and you begin to feel a damp sensation coming over you. you feel the urge to ove forward.

%^COLOR220%^Well lit torches line the room.%^RESET%^
EndText);

add_exit(PATH+"r38.c", "north");
//add_exit(PATH+"r34.c", "east");
add_exit(PATH+"r103.c", "south");
//add_exit(PATH+"r35.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
