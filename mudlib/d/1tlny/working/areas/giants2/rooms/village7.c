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
The stone houses tower all around you just like everywhere 
in this village except from the east where you notice a road 
surrounded by walls. Although you can't tell much from here, 
the area to the east of you seems much more decorated then 
this one. 
EndText
);  
    set( "night long", @EndText
The stone houses tower all around you just like everywhere 
in this village except from the east where you notice a road 
surrounded by walls. Although you can't tell much from here, 
the area to the east of you seems much more decorated then 
this one.
EndText
);  
    add_item("houses","Stone buildings the size of a hill.. you notice that
the roofs are at the same height as the surrounding walls.");
    add_item("walls","These walls towers no less then 30 feet above you.");
    add_item("wall","The wall towers 30 feet above you.");
    add_item("road","The stonebricks are firmly attached, making this road
very pleasant");
    
    set_exits( ({
ROOMS_PATH+"village5",ROOMS_PATH+"village10",ROOMS_PATH+"village6",ROOMS_PATH+"temple road" }), ({
"south", "north", "west",
"east" }) );
}
