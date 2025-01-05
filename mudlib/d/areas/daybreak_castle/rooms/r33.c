#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void reset() {
        ::reset();
if (!present("bat")) 
new(MON+"bat.c")->move(this_object());
new(MON+"bat.c")->move(this_object());
new(MON+"bat.c")->move(this_object());
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
You are closely surrounded by cob webs and dust. The tall, towering
ceilings above you has cracks an looks like it could fall apart and collapse at any moment.
	
	
EndText);

    set( "night long", @EndText
You are closely surrounded by cob webs and dust. The tall, towering
ceilings above you has cracks an looks like it could fall apart and collapse at any moment.
EndText);

//add_exit(PATH+"r137.c", "north");
//add_exit(PATH+"r136.c", "southwest");
add_exit(PATH+"r32.c", "east");
add_exit(PATH+"r132.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
