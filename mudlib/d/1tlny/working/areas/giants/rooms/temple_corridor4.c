#include <std.h>
#include "giants_paths.h"
inherit "/std/vault";

void create()
{
    ::create();
    set_property("light", 4);
    set_property("indoors", 1);
    set( "short", "Temple Corridor." );
    set( "long", @EndText
Towering before you at this northern end of the
corridor is a huge wooden door. A beautiful chande-
lier lights up the room and as the light hits the
rock walls, light in various colours reflect onto
the floor. There is a golden engraving on the door.
EndText
);
    add_item("chandelier", "A beautiful chandelier provides a very
colourful light here.");
    add_item("engraving", "The golden engraving reads 'In honour of
K'az-ra, Father of the Holy Temple Order'.");
    set_listen("default", "You hear a loud murmuring sound coming from the
north.");
    set_door("door", ROOMS_PATH+"temple_room2", "north", "temple key");
    set_open("door", 0);
    set_locked("door", 0);
    set_exits( ({ ROOMS_PATH+"temple_corridor3", ROOMS_PATH+"temple_room2"
}), ({ "south", "north" }) );
}

