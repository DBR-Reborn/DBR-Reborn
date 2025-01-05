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
You find yourself walking on a road that is so rough 
that you fear getting stuck between the stonebricks. 
To the east you see the towering village and the road 
stretches northwestwards into what appears to be an 
open area.
EndText
);  
    set( "night long", @EndText
You find yourself walking on a road that is so rough 
that you fear getting stuck between the stonebricks. 
To the east you see the towering village and the road 
stretches northwestwards into what appears to be an 
open area.
EndText
);  
    add_item("walls","These walls towers no less then 30 feet above you.");
    add_item("wall","The wall towers 30 feet above you.");
    add_item("road","The stonebricks seems to be put here without any effort from the roadbuilders");
    
    set_exits( ({
ROOMS_PATH+"village9",ROOMS_PATH+"camp1" }), ({
"east", "west" }) );
}
