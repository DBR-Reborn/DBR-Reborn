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
This small road links the main village with the marketplace 
further south. Directly to the north lies the main village 
and lots of citizens can be seen, socializing and dealing 
with their daily tasks.
EndText
);  
    set( "night long", @EndText 
This small road links the main village with the marketplace 
further south. Directly to the north lies the main village
and some citizens can be see. Their loud voices tells you 
they are probably roaring drunk. Better be careful so none 
of them steps on you.
EndText
); 
    add_item("walls","These walls towers no less then 30 feet above you.");
    add_item("wall","The wall towers 30 feet above you.");
    add_item("road","The stonebricks are firmly attached, making this road
very pleasant");
    
    set_exits( ({ ROOMS_PATH+"village3",ROOMS_PATH+"village1" }), ({
"north",
"southeast" }) );
}
