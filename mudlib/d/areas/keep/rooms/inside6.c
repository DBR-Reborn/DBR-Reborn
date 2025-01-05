#include <std.h>
#include "../keep.h"

/* This is the first room of the keeps western hall. Only two of the four rooms in each of the west and east hallways from the great hall contain mobs, and this one is one of the rooms that does not. To the east is the great hall, and to the north is an abandoned room locked by a red door, which requires the blood key found outside to open. The south exit leads to a laboratory. */

inherit "/std/vault";

void create() {
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A long dark hallway");
set_long(@ext Walking down the dark hallway, you can make out two small archways to your north and south, passage beyond the north obstructed by a red door, and the south leading to a room that likely belonged to a former resident of the keep. You see a dark passage with no visible features in sight to your west and what appears to be a four way intersection not far to your east. As far as the rough walls, smooth floor, and smooth ceiling of the room are concerned, they are completely black and plain.
    0   
    |   
 0--@--0
    |
    0
ext);
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside10", "north");
add_exit(ROOMS+"inside11", "west");
add_exit(ROOMS+"inside12", "south");
add_exit(ROOMS+"inside4", "east");
set_door("red door", ROOMS+"inside10", "north", "blood key");
set_open("red door", 0);
set_locked("red door", 1);
set_lock_level("red door", 1000);
set_items(([
({ "keep" }) : "The keep from within appears to be extremely dark and haunted.",
({ "hallway" }) : "This is a long dark hallway, with exits in all four directions.",
({ "intersection" }) : "What seems to be a four way intersection is barely seen to the east.",
({ "walls" }) : "The walls are fashioned of rough black stone and are completely plain.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning the ceiling and floor is very smooth.",
({ "passage" }) : "The passage appears very dark and can lead to anywhere.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon.",
({ "ceiling" }) : "The ceiling is well crafted of black stone and is very smooth.",
({ "archway" }) : "This is an archway that serves as an entrance to the adjoining room.",
({ "archways" }) : "These archways serve as entrances to the adjoining north and south rooms respectively. A red door is blocking access beyond the north archway.",
({ "red door" }) : "This is a relatively bright red door, with a pentagram symbol above its center and a keyhole shaped like a horizontal line with a very small vertical line descending from its center is located on the middle right half.",
({ "door" }) : "This is a relatively bright red door, with a pentagram symbol above its center and a keyhole shaped like a horizontal line with a very small vertical line descending from its center is located on the middle right half.",
({ "north archway" }) : "This is an archway that serves as an entrance to the adjoining north room. A red door is obstructing passage beyond it.",
({ "room" }) : "The room to your south appears to be medium sized, and judging by its location likely served residental purpose for a former occupant of the keep.",
]));
}
