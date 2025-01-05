#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "A mammoth cage." );
    set( "day long", @EndText
This mammoth cage looks just like a prison, except its
enormous size and the lack of a roof. The walls looks very 
solid and you realize that no one can break out of here. 
At least not using pure strength. The location of the cage 
tells you that mammoths are probably kept here as some part 
of the military training. In the mud, huge footprints can be
seen. 
EndText 
); 

set( "night long", @EndText
This mammoth cage looks just like a prison, except its
enormous size and the lack of a roof. The walls looks very 
solid and you realize that no one can break out of here. 
At least not using pure strength. The location of the cage 
tells you that mammoths are probably kept here as some part 
of the military training. In the mud, huge footprints can be
seen.
EndText 
); 
    
    add_item("cage","The cage seems very solid. The huge stone door that
blocks the entrance
is reinforced with iron bars."); 
    add_item("door","A stone door reinforced with iron bars.");
    add_item("mud","Huge footprints can be seen everywhere in the mud."); 
    add_item("walls","This cage is HUGE."); 
    add_item("wall","The wall towers almost 30 feet above you.");
    add_item("footprints","Looks like mammoth footprints.");
    set_smell("default", "Dust from the walls fills your lungs, making it hard to breathe.");

    set_exits( ({
ROOMS_PATH+"camp4" }), ({
"south" }) );
}
