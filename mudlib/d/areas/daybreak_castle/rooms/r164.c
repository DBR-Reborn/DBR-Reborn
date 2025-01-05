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
new(MON+"rat.c")->move(this_object());
new(MON+"rat.c")->move(this_object());
new(MON+"rat.c")->move(this_object());
new(MON+"ghost soldier.c")->move(this_object());

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
ceilings above you has cracks an looks like it could fall apart and collapse at any moment. you can hear bats over your head and rat tracks along the dust on the floor.
	
	
EndText);

    set( "night long", @EndText
You are closely surrounded by cob webs and dust. The tall, towering
ceilings above you has cracks an looks like it could fall apart and collapse at any moment. you can hear bats over your head and rat tracks along the dust on the floor.
	
EndText);

//add_exit(PATH+"r149.c", "north");
add_exit(PATH+"r166.c", "southeast");
//add_exit(PATH+"r151.c", "south");
add_exit(PATH+"r162.c", "northwest");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
