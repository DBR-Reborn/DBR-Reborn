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
You continue your walk on this impressive road. A glint of the walls
surrounding you is enough to make you feel dizzy. Better keep your
sight down from now on. The road continues to the west and north.
EndText
);
    set( "night long", @EndText
You continue your walk on this impressive road. A glint of the walls
surrounding you is enough to make you feel dizzy. Better keep your
sight down from now on. The road continues to the west and north.
EndText
);
         add_item("walls","The walls stands very close at this part.");
         add_item("wall","This impressive wall seem to tower no less
than 30 feet above you.");
         add_item("road","A huge road covered with stonebricks.");

    set_exits( ({ ROOMS_PATH+"road3", ROOMS_PATH+"road5" }), ({ "west",
"north" }) );
}

