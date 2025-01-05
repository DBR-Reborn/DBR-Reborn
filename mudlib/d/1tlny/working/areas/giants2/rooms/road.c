#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "A small road." );
    set( "day long", @EndText
The stone walls sure are impressive. Although this village
seems to be populated with Storm-Giants you can't help
but wonder how they have managed to build walls like these.
The rocks that are used for the walls seems to be the size
of houses. Between the stone walls a small road slingers.
To the west a guard post can be seen and the road continues
eastwards.
EndText 

);
    set( "night long", @EndText
The stone walls sure are impressive. Although this village
seems to be populated with Storm-Giants you can't help
but wonder how they have managed to build walls like these.
The rocks that are used for the walls seems to be the size
of houses. Between the stone walls a small road slingers.
To the west a guard post can be seen and the road continues
eastwards.
EndText
); 
           add_item("walls","These impressive walls seem to tower no less
than 30 feet above you.");
           add_item("rocks","The rocks are HUGE but seems to be attached 
securely to the wall.");
    set_exits( ({ ROOMS_PATH+"entrance", ROOMS_PATH+"road2" }), ({ "west",
"east" }) );
}

