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
It is %^YELLOW%^day%^RESET%^ outside.
    You are standing undr a huge curved arch-way where the draw-bridge sits when closed. You see a series of pullies on either side of the arch walls. To the north is the main square of the castle which has a small fire pit left behind by looters.
EndText);

    set( "night long", @EndText
It is %^BOLD%^BLUE%^night%^RESET%^ outside.
        You are standing undr a huge curved arch-way where the draw-bridge sits when closed. You see a series of pullies on either side of the arch walls. To the north is the main square of the castle which has a small fire pit left behind by looters.
EndText);

add_exit(PATH+"r4.c", "square");
add_exit(PATH+"r2.c", "south");
//add_exit(PATH+"r4.c", "east");
//add_exit(PATH+"r5.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
