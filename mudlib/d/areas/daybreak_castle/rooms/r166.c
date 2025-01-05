#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void reset() {
        ::reset();
if (!present("guard")) 
new(MON+"guard.c")->move(this_object());
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
You are closely surrounded by dense cracking walls. The tall, towering
ceilings above are grumbling over your head. There are no signs of life other than beast hovering over you. he seems to be the boss of all these creatures you had fought to get here. This creature might be worth killing to help you continue through your next journey through the castle.

%^ORANGE%^You smell and see bones of all life scattered throughout the floor barely having anywhere to walk%^RESET%^	
	
EndText);

    set( "night long", @EndText
You are closely surrounded by dense cracking walls. The tall, towering
ceilings above are grumbling over your head. There are no signs of life other than beast hovering over you. he seems to be the boss of all these creatures you had fought to get here. This creature might be worth killing to help you continue through your next journey through the castle.

%^ORANGE%^You smell and see bones of all life scattered throughout the floor barely having anywhere to walk%^RESET%^	

EndText);

//add_exit(PATH+"r149.c", "north");
add_exit(PATH+"r165.c", "northeast");
//add_exit(PATH+"r151.c", "south");
add_exit(PATH+"r164.c", "northwest");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
