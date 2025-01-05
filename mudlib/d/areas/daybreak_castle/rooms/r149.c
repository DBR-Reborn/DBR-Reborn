#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void reset() {
        ::reset();
if (!present("Castle Guard")) 
new(MON+"castleguard.c")->move(this_object());

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
you are walking through a side pathway that has never been traveled. you feel the sense of treasure towards the end of this pathway. as you look around yu can see this room is cleaner than the others.

%^COLOR65%^ You hear a %^COLOR85%^growl%^RESET%^ %^COLOR65%^further down the pathway.%^RESET%^	
EndText);

    set( "night long", @EndText
you are walking through a side pathway that has never been traveled. you feel the sense of treasure towards the end of this pathway. as you look around yu can see this room is cleaner than the others.

%^COLOR65%^ You hear a %^COLOR85%^growl%^RESET%^ %^COLOR65%^further down the pathway.%^RESET%^
EndText);

//add_exit(PATH+"r133.c", "north");
//add_exit(PATH+"r146.c", "east");
add_exit(PATH+"r150.c", "south");
add_exit(PATH+"r124.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
