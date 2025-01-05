#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set( "short", "Entrance to the Temple of K'az-ra." );
    set( "long", @EndText
You are at the entrance to the temple of K'az-ra. A
wide corridor leads east. On the walls, torches are
placed to provide a soft light. The floor is made of
huge stone blocks, shaped to be perfectly flat. There
is a slight breeze here, blowing up some dust from
the floor.
EndText
);
    add_item("torches", "Torches are securely fastened to the walls.");
    set_exits( ({ ROOMS_PATH+"temple_corridor1", }), ({ "east" }) );
}

