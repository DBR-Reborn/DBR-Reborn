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
The road widens here and to the north you see a marketplace. You 
can actually see some of the citizens, but although they aren't 
far away it seems surprisingly quiet.
The road continues to the south and north.
EndText
);
    set( "night long", @EndText
The road widens here and to the north is something that looks like a
marketplace. No citizens can be seen and no sounds can be heard but 
you imagine it's different during the day. 
The road continues to the south and north.
EndText
);
    add_item("walls","These walls towers no less then 30 feet above you.");
    add_item("wall","The wall towers 30 feet above you.");
    add_item("road","This road is covered with huge stonebricks.");
    add_item("marketplace","Hard to tell anything from here. Perhaps you should 
go further north.");
  
    set_exits( ({ ROOMS_PATH+"road4", ROOMS_PATH+"road6" }), ({ "south",
"north" }) );
}
