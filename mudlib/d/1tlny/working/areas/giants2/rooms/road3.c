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
You carefully walk along the road. Don't wanna get youre feet stuck between
the enormous stonebricks you're walking on. Wiping some dust out of your
face you decide to move on. The road continues to the east and west.
EndText
);
    set( "night long", @EndText
You carefully walk along the road. Don't wanna get youre feet stuck between
the enormous stonebricks you're walking on. Wiping some dust out of your
face you decide to move on. The road continues to the east and west.
EndText
); 
       add_item("walls","These impressive walls seem to tower no less
than 30 feet above you.");
       add_item("wall","This impressive wall seem to tower no less
than 30 feet above you.");
       add_item("bricks","These stonebricks gives this road a very solid impression.");
       add_item("road","The stonebricks this road is made of makes it very impressive.");
       add_item("face","The dust almost covers your ugly appearance.");    
      
       set_exits( ({ ROOMS_PATH+"road2", ROOMS_PATH+"road4" }), ({ "west",
"east" }) );
}
