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
You have entered the northern parts of the village. Even 
this area seems well populated. The Storm-Giants sure 
have used the space well. To the north you see a house 
that appears to be open.
EndText
);  
    set( "night long", @EndText
You have entered the northern parts of the village. Even 
this area seems well populated. The Storm-Giants sure 
have used the space well. To the north you see a house 
that appears to be open.
EndText
);  
    add_item("houses","Stone buildings the size of a hill.. you notice that
the roofs are at the same height as the surrounding walls.");
    add_item("walls","These walls towers no less then 30 feet above you.");
    add_item("wall","The wall towers 30 feet above you.");
    add_item("road","The stonebricks are firmly attached, making this road
very pleasant");
    
    set_exits( ({
ROOMS_PATH+"village7",ROOMS_PATH+"house2",ROOMS_PATH+"village9" }), ({
"south", "north", "west" }) );
}
