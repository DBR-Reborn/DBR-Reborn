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
At this hour the village is burstling with activity. 
Storm-Giants off all ages can be seen. Better watch out,
some almost 10 feet tall kids doesnt seem to notice you
as they throw each other around. To the west you notice 
that one of the towering houses stands open.   
EndText
);  
    set( "night long", @EndText
The village seems very quiet at this hour, the towering
houses reflects shadows from the moonligth all around you.
Some noise can be heard from the southeast. To the west 
you notice that one of the towering houses stands open.  
EndText
);  
    add_item("houses","Stone buildings the size of a hill.. you notice that the roofs are at the same height as the surrounding walls.");
    add_item("walls","These walls towers no less then 30 feet above you.");
    add_item("wall","The wall towers 30 feet above you.");
    add_item("road","The stonebricks are firmly attached, making this road
very pleasant");
    
    set_exits( ({ ROOMS_PATH+"village6",ROOMS_PATH+"house1",ROOMS_PATH+"village5" }), ({
"north", "west",
"east" }) );
}
