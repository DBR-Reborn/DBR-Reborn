#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void reset() {
        ::reset();
if (!present("castle warrior")) 
new(MON+"castlewarrior.c")->move(this_object());
new(MON+"castlewarrior.c")->move(this_object());
new(MON+"castleguard.c")->move(this_object());
new(MON+"castlewarrior.c")->move(this_object());
new(MON+"castleguard.c")->move(this_object());
new(MON+"castlewarrior.c")->move(this_object());
new(MON+"castleguard.c")->move(this_object());
new(MON+"peasant.c")->move(this_object());
new(MON+"castleguard.c")->move(this_object());
new(MON+"castlewarrior.c")->move(this_object());
new(MON+"peasant.c")->move(this_object());
new(MON+"castlewarrior.c")->move(this_object());
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



	
EndText);

    set( "night long", @EndText
you are walking through a side pathway that has never been traveled. you feel the sense of treasure towards the end of this pathway. as you look around yu can see this room is cleaner than the others.



EndText);

add_exit(PATH+"r149.c", "north");
//add_exit(PATH+"r146.c", "east");
add_exit(PATH+"r151.c", "south");
//add_exit(PATH+"r144.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
