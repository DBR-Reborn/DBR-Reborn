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
This small road links the main village with the marketplace to the 
south. Unlike most roads in this village the roadbuilders seem to 
have put a great deal of effort in this one. The stonebricks are 
firmly attached, making this road very pleasant. The road continues
to the nortwest and to the south you see the marketplace.
EndText
);  

    set( "night long", @EndText 
This small road links the main village with the marketplace to the 
south. Unlike most roads in this village the roadbuilders seem to 
have put a great deal of effort in this one. The stonebricks are 
firmly attached, making this road very pleasant. The road continues
to the nortwest and to the south you see the marketplace.
EndText
); 
    add_item("walls","These walls towers no less then 30 feet above you.");
    add_item("wall","The wall towers 30 feet above you.");
    add_item("road","The road is covered with huge firmly attached stonebricks.");
    
    set_exits( ({ ROOMS_PATH+"village2",ROOMS_PATH+"market21" }), ({ "northwest",
"south" }) );     
}
