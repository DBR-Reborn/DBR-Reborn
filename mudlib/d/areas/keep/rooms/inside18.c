#include <std.h>
#include "../keep.h"

/* This is the room of the black keep that contains the entrance to the Dark Paladin Guild. There are no monsters present in this room, for the purpose that the player should be able to focus on the swirling shadow. If a player who is either a child with no guild or a dark paladin, they will be transported directly to the dark paladin guild. If the player is not one of the previous two classes, they will be taken to the town in the underworld. The only other exit from this room not concerning the shadow portal is south, back into the keep's western hall. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A bare empty room");
set_long(@ext This room is completely empty of any materialistic possessions. The walls, ceiling, and floor are all completely bare, and not a single sound can be heard. However, hovering in the direct center of the room, halfway between the top and bottom, is a swirling shadow. Perhaps this room serves as a gateway to another place, or it can just be the location of failed magic.
   
    @
    |
    0
ext);  
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You dont hear a sound.");
add_exit(ROOMS+"inside11", "south");
ob = new(ITEM+"swirling_shadow.c");
ob->move(this_object());
set_items(([
({ "walls" }) : "The walls are fashioned of rough black stone and are completely plain.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon. A swirling shadow hovers above halfway between it and the ceiling.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning the floor and ceiling is very smooth.",
({ "ceiling" }) : "The ceiling is well crafted of black stone and is very smooth. A swirling shadow hovers below halfway between it and the floor.",
({ "center" }) : "At the center of the room, a swirling shadow hovers halfway between the ceiling and floor.",
({ "room" }) : "This room is completely bare. However, a swirling shadow can be seen hovering in the center.",
({ "top" }) : "The top of the room consists of a bare stone ceiling. A swirling shadow hovers below it.",
({ "bottom" }) : "The bottom of the room consists of a smooth stone floor. A swirling shadow hovers above it.",
]));
}
