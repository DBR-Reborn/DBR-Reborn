#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;


void reset() {
        ::reset();
if (!present("castle warrior")) 
new(MON+"castlewarrior.c")->move(this_object());
new(MON+"castleguard.c")->move(this_object());
new(MON+"castleguard.c")->move(this_object());
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
This is a pathway through the castle, usually populated by many people, now deserted. It seems you have a few pathways to move forward but all exits except the one you came from will lead you to a possible doom.

%^COLOR206%^You can hear screams for help off in the distance.%^RESET%^
	
	
EndText);

    set( "night long", @EndText
This is a pathway through the castle, usually populated by many people, now deserted. It seems you have a few pathways to move forward but all exits except the one you came from will lead you to a possible doom.

%^COLOR206%^You can hear screams for help off in the distance.%^RESET%^
	
	
EndText);

add_exit(PATH+"r123.c", "north");
add_exit(PATH+"r149.c", "east");
add_exit(PATH+"r125.c", "southwest");
//add_exit(PATH+"r109.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
