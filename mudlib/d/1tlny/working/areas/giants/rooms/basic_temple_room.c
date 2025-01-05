#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set( "short", "" );
    set( "long", @EndText

EndText
);
    set_exits( ({ ROOM_PATH+"ga2.c", }), ({ "north" }) );
}

