#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "A small road." );
    set( "day long", @EndText
Between the stone bricks, a lot of mud has got stuck 
making the road rather smooth. To the north you see 
a large area that unlike the rest of the village
doesn't seem to have a stone ground. A lot of noise 
can be heard and you see small groups of Storm-Giants 
performing what appears to be some kind of exercise. 
East of you is a rough looking road.
EndText 
);  
    set( "night long", @EndText
Between the stone bricks, a lot of mud has got stuck 
making the road rather smooth. To the north you see 
a large area that unlike the the rest of the village
doesn't seem to have a stone ground. East of you is 
a rough looking road.
EndText
);   
    add_item("road","The mud makes the angular stone bricks less
uncomfortable");
    add_item("mud","It's filthy and disgusting.");
    add_item("walls","These walls towers no less then 30 feet above you.");
    add_item("wall","The wall towers 30 feet above you.");
    set_smell("default", "Dust from the walls fills your lungs, making it hard to breathe.");   
    set_exits( ({
ROOMS_PATH+"camp2",ROOMS_PATH+"village8" }), ({
"north", "east" }) );
}
