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
The stone houses and walls towers around the village. 
Pondering how many normal people one of those houses could 
inhabit you smirk as you remind yourself of the sprite
villages you have seen. To the northeast you see a road 
leading out of the village.  
EndText
);  
    set( "night long", @EndText
The stone houses and walls towers around the village. 
Pondering how many normal people one of those houses could 
inhabit you smirk as you remind yourself of the sprite
villages you have seen. To the northeast you see a road 
leading out of the village 
EndText
);  
    add_item("houses","Stone buildings the size of a hill.. you notice that the roofs are at the same height as the surrounding walls.");
    add_item("walls","These walls towers no less then 30 feet above you.");
    add_item("wall","The wall towers 30 feet above you.");
    add_item("road","The stonebricks are firmly attached, making this road
very pleasant");
    
    set_exits( ({ ROOMS_PATH+"village7",ROOMS_PATH+"village4",ROOMS_PATH+"village3" }), ({
"north", "west",
"south" }) );
}
