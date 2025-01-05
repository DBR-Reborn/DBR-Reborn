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
You are standing in the northwest corner of the sacred
temple chamber of K'az-ra. The room is centred around a
great statue by the northern wall. Light falls down on
the statue in billions of shades. The magical power in
this room is very strong and you do not at all feel
pleasant about intruding this sacred place. The walls
are covered with paintings. You see a few of the paintings
clearly here. A small hole in the western wall has a little
fire in it. Next to the hole there is a small plaque.
EndText
);
    add_item("statue",
"A huge statue of a storm-giant dressed entirely in a shining
black armour is by the northern wall in the chamber.");
    add_item("paintings",
"The paintings show a warrior, dressed in black, standing
on top of a vulcanic mountain, with his sword raised against
the sky. The Sky is in a magnificent mix of yellow and red
nuances.");
    add_item("fire",
"The little fire in the hole burns softly, even though there is a
small breeze in here, it does not seem to flicker at all.");
    add_item("hole",
"A small fire burns in the hole, there is a small plaque by the hole.");
    add_item("plaque",
"With black letters on a golden background the plaque reads
[%^B_YELLOW%^%^BOLD%^%^BLACK%^THE ETERNAL FLAME OF K'AZ-RA%^RESET%^]");
    set_exits( ({ ROOMS_PATH+"temple_room1", ROOMS_PATH+"temple_room5",
 }), ({ "south", "east" }) );
}

