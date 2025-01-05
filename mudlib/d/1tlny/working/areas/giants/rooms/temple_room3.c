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
You are standing in the southeast corner of the sacred
temple chamber of K'az-ra. The room is centred around a
great statue by the northern wall. Light falls down on
the statue in billions of shades. The magical power in
this room is very strong and you do not at all feel
pleasant about intruding this sacred place. The walls
are covered with paintings. You see a few of the paintings
clearly here.
EndText
);
    add_item("statue",
"A huge statue of a storm-giant dressed entirely in a shining
black armour is by the northern wall in the chamber.");
    add_item("paintings",
"A huge warrior, dressed in a shining black armour, stands
in front of a portal. The portal is shimmering in a green
light.");
    set_exits( ({ ROOMS_PATH+"temple_room6", ROOMS_PATH+"temple_room2",
 }), ({ "north", "west" }) );
}

