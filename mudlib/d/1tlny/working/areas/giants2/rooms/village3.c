#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Villageroad." );
    set( "day long", @EndText
All around you the huge citizens of this village can be seen.
Some of them eyes you suspiciously since visitors usually
doesn't enter this region of the village. Large houses built
entirely of stone is in all directions. To the east you see
the entrance to the Golden Mammoth tavern.
EndText
);  
    set( "night long", @EndText
Large houses built entirely of stone is in all directions.
Some loud citiens passes by on their way to and from the 
Golden Mammoth tavern that can be seen to the east. 
EndText
);  
    add_item("tavern","The Golden Mammoth tavern, perhaps you should enter.");
    add_item("houses","Stone buildings the size of a hill.. you notice that the roofs are at the same height as the surrounding walls.");
    add_item("walls","These walls towers no less then 30 feet above you.");
    add_item("wall","The wall towers 30 feet above you.");
    add_item("road","The stonebricks are firmly attached, making this road
very pleasant");
    
    set_exits( ({ ROOMS_PATH+"village5",ROOMS_PATH+"tavern",ROOMS_PATH+"village2" }), ({
"north", "east",
"south" }) );
}
