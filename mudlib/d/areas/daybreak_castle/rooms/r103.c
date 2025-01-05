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
This is the south end of DayBreak Castle, bodies lay aong the floor, while a layer of decay rests upon each other. Off to the north is a dark pathway, you can't see anything past a few feet of the archway to it.
 
%^COLOR202%^It smells like death in the air.%^RESET%^
EndText);

    set( "night long", @EndText
This is the south end of DayBreak Castle, bodies lay aong the floor, while a layer of decay rests upon each other. Off to the north is a dark pathway, you can't see anything past a few feet of the archway to it.
 
%^COLOR202%^It smells like death in the air.%^RESET%^
EndText);

add_exit(PATH+"r42.c", "north");
add_exit(PATH+"r127.c", "east");
//add_exit(PATH+"r64.c", "south");
add_exit(PATH+"r94.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
