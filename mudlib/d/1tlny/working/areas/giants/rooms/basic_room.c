#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "" );
    set( "day long", @EndText

EndText
);
    set( "night long", @EndText

EndText
);
    set_exits( ({ ROOM_PATH+"ga2.c", }), ({ "north" }) );
}

