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
As you find youself in the middle of this village you 
take a good look around you. There seems to be almost a 
hundred of these huge houses here. The amount of stone 
required for all of this must be the size of a mountain. 
Minimum. Where could they have gotten it all from? 
EndText
);  
    set( "night long", @EndText 
As you find youself in the middle of this village you 
take a good look around you. There seems to be almost a 
hundred of these huge houses here. The amount of stone 
required for all of this must be the size of a mountain. 
Minimum. Where could they have gotten it all from?  
EndText
);  
    add_item("houses","Stone buildings the size of a hill.. you notice that
the roofs are at the same height as the surrounding walls.");
    add_item("walls","These walls towers no less then 30 feet above you.");
    add_item("wall","The wall towers 30 feet above you.");
    add_item("road","The stonebricks are firmly attached, making this road
very pleasant");
    
    set_exits( ({
ROOMS_PATH+"village4",ROOMS_PATH+"village9",ROOMS_PATH+"village7" }), ({
"south", "north",
"east" }) );
}
