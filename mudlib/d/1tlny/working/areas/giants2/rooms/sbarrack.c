#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 3);
    set( "short", "Southern Guard Barrack." );
    set( "day long", @EndText
You have entered the southern guard barrack. Here guards can
rest when not on duty and brag about the battles in which they
have participated. Some strange marks can be seen in the walls 
and to the east is an open door leading into another room. 
To the north you see a road.
EndText
);
    set( "night long", @EndText
This guard barrack is lit up by a lantern hanging from the 
southern wall. In this brightness strange marks can be seen 
in the walls and to the east is an open door leading into 
another room. To the north you see a road.
EndText
);
            add_item("strange marks","Marks the size of a head... or a Storm-Giants hand... 
you shiver....");
            add_item("marks","Marks the size of a head... or a Storm-Giants hand... 
you shiver....");
            add_item("walls","These impressive walls seem to tower no less
than 30 feet above you.");
            add_item("southern wall","A lantern hangs from this huge wall, shrouding the room with light.");



    set_exits( ({ ROOMS_PATH+"road2", ROOMS_PATH+"sebarrac" }), ({ "north",
"east" }) );
}
