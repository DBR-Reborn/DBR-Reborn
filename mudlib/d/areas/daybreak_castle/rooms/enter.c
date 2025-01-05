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
It is muggy outside with tall trees blocking any daylight.

    You are standing on a heavily traveled dirt path leading to a base of DayBreak Castle. You can see a raised draw bridge at the entrance of the castle. It is known Trolls guard this area and will not always let you pass.
EndText);

    set( "night long", @EndText
It is %^BOLD%^BLUE%^night%^RESET%^ outside.
    You are standing just inside the entrance.
EndText);

add_exit(PATH+"r1.c", "north");
//add_exit(PATH+"r2.c", "south");
//add_exit(PATH+"r3.c", "east");
//add_exit(PATH+"r4.c", "west");
add_exit("/d/damned/virtual/room_8_5.world", "exit");
    //add_invis_exit("north");

}
