#include <std.h>
#include "giants_paths.h"
inherit ROOM;

void create()
{
    ::create();
    set_property("light", 4);
    set_property("indoors", 1);
    set( "short", "Temple Chamber" );
    set( "long", @EndText
You are standing in the northeastern corner of the sacred
temple chamber of K'az-ra. The room is centred around a
great statue by the northern wall. Light falls down on
the statue in billions of shades. The magical power in
this room is very strong and you do not at all feel
pleasant about intruding this sacred place. The walls
are covered with paintings. You see a couple of paintings
clearly here. Carved into the eastern wall is a small hole,
inside the hole some water is pouring. Next to the hole is
a plaque.
EndText
);
    add_item("statue",
"A huge statue of a storm-giant dressed entirely in a shining
black armour is by the northern wall in the chamber.");
    add_item("paintings",
"These paintings have a slightly different look than the rest
you have seen around here. The sky is dark and clouded and on
the ground a warrior is lying down, his black armour is dirty
and broken in several places. Blood stains are everywhere around
him.");
    add_item("hole",
"A small hole with a miniature waterfall is carved into the wall.
Next to the hole is a plaque.");
    add_item("waterfall",
"Inside the hole is a small waterfall.");
    add_item("water",
"Some water is pouring inside the hole, it looks like a miniature
waterfall.");
    add_item("plaque",
"The plaque reads with white letters on a blue background
[%^B_BLUE%^%^WHITE%^THE BLOOD OF K'AZ-RA, FATHER%^RESET%^]");
    set_exits( ({ ROOMS_PATH+"temple_room5", ROOMS_PATH+"temple_room3",
 }), ({ "west", "south" }) );
}

