#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void reset() {
        ::reset();
if (!present("rat")) 
new(MON+"rat.c")->move(this_object());
new(MON+"rat.c")->move(this_object());
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
It is %^YELLOW%^day%^RESET%^ outside.
    You are standing on an unstable draw-bridge which is being held by thin strips of damage twine.
EndText);

    set( "night long", @EndText
It is %^BOLD%^BLUE%^night%^RESET%^ outside.
    You are standing on an unstable draw-bridge with moving shadows off in the distance.
EndText);

add_exit(PATH+"r3.c", "north");
add_exit(PATH+"r1.c", "bridge");
//add_exit(PATH+"r4.c", "east");
//add_exit(PATH+"r5.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
