#include <std.h>
#include "giants_paths.h"
inherit ROOM;

void create()
{
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set( "short", "Western Guard Room" );
    set( "long", @EndText
This is the western of the two temple guard rooms.
It is made very simple as an alcove to the corridor,
that is east of here. Some torches keep the room well-
lit.
EndText
);
    add_item("torches", "A few torches provide light here.");
    set_exits( ({ ROOMS_PATH+"temple_corridor2" }), ({ "east" }) );
}

