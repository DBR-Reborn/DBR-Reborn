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
While you enter this room you see a group of sprites flying around a dead corpse. these sprites have sharp teeth like razor blades. once you attack one, they all will protect each other and fight as a sworm. they wont stop attack until they are all dead. 

%^YELLOW%^You see a %^RED%^dead %^YELLOW%^corpse laying on the floor with it's bones picked cleaned.

EndText);

    set( "night long", @EndText
While you enter this room you see a group of sprites flying around a dead corpse. these sprites have sharp teeth like razor blades. once you attack one, they all will protect each other and fight as a sworm. they wont stop attack until they are all dead. 

%^YELLOW%^You see a %^RED%^dead %^YELLOW%^corpse laying on the floor with it's bones picked cleaned.
EndText);

//add_exit(PATH+"r89.c", "north");
add_exit(PATH+"r91.c", "east");
//add_exit(PATH+"r37.c", "south");
add_exit(PATH+"r89.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
