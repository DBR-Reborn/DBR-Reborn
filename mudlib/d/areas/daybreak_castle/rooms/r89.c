#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void reset() {
        ::reset();
if (!present("castle warrior")) 
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
While continuing to walk north with east the only direction you can go other than where you came from, you still see along the walls claw marks which has turned into blood as if someone had been dragged against their will who had their finger nails ripped off along with some fingers. further around the corner you notice something ran far off in the distance, you can't seem to make this creature out but notice it was tall and skinny and moved faster than any race. you are compelled to keep moving forward east.
	
	
EndText);

    set( "night long", @EndText
While continuing to walk north with east the only direction you can go other than where you came from, you still see along the walls claw marks which has turned into blood as if someone had been dragged against their will who had their finger nails ripped off along with some fingers. further around the corner you notice something ran far off in the distance, you can't seem to make this creature out but notice it was tall and skinny and moved faster than any race. you are compelled to keep moving forward east.

EndText);

//add_exit(PATH+"r89.c", "north");
add_exit(PATH+"r90.c", "east");
add_exit(PATH+"r40.c", "south");
//add_exit(PATH+"r49.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
