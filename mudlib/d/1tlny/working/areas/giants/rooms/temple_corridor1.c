#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set( "short", "Temple Corridor." );
    set( "long", @EndText
You find yourself just east of the temple entrance.
This is a quite narrow corridor for being fashioned
by storm-giants. Torches fastened to the walls provide
a soft light and shadows dance on the stone walls. On
the eastern wall a gold plaque is attached.
EndText
);
    add_item("torches", "Torches are securely fastened to the walls.");
    add_item("plaque", "The plaque reads 'Holy temple of K'az-ra'.");
    set_listen("default", "You hear a deep murmuring sound somewhere from
the north.");
    set_exits( ({ ROOMS_PATH+"temple_corridor2",
ROOMS_PATH+"temple_entrance" }), ({ "north", "west" }) );
}

