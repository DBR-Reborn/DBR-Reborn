#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Village." );
    set( "day long", @EndText
At this part the village seems to be less crowded with 
houses. Only a few can be seen and to the west of you 
is a rough looking road.
EndText
);  
    set( "night long", @EndText
At this part the village seems to be less crowded with 
houses. Only a few can be seen and to the west of you 
is a rough looking road.
EndText
);  
    add_item("houses","Stone buildings the size of a hill.. you notice that
the roofs are at the same height as the surrounding walls.");
    add_item("walls","These walls towers no less then 30 feet above you.");
    add_item("wall","The wall towers 30 feet above you.");
    add_item("road","The stonebricks are firmly attached, making this road
very pleasant");
    
    set_exits( ({
ROOMS_PATH+"village6",ROOMS_PATH+"village10",ROOMS_PATH+"village8" }), ({
"south", "east", "west" }) );
}
