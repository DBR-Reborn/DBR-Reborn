#include <std.h>
#include "giants_paths.h"
inherit "/std/vault";

void create()
{
    ::create();
    set_property("light", 4);
    set_property("indoors", 1);
    set( "short", "Temple Chamber" );
    set( "long", @EndText
You have made your into the sacred temple chamber of
K'az-ra. The room is centred around a great statue by
the northern wall. Light falls down on the statue in
billions of shades. The magical power in this room is
very strong and you do not at all feel pleasant about
intruding this sacred place. The walls are covered with
paintings.
EndText
);
    add_item("statue", "A huge statue of a storm-giant dressed entirely in
a shining black armour is by the northern wall in the chamber.");
    add_item("paintings", "The light in the room makes it impossible for
you to see what the paintings portrait from this point of view.");
    set_door("door", ROOMS_PATH+"temple_corridor4", "south", "temple key");
    set_open("door", 0);
    set_locked("door", 0);
    set_exits( ({ ROOMS_PATH+"temple_room1", ROOMS_PATH+"temple_room3",
ROOMS_PATH+"temple_corridor4", ROOMS_PATH+"temple_room5" }), ({ "west",
"east", "south", "north" }) );
}

