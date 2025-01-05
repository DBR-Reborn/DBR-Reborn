#include <std.h>
#include "../keep.h"

/* This is the first room of the eastern hall of the black keep. In both the east and west hallways, only two of the four rooms contain mobs. This is to prevent the area from becoming a mob farm. This is one of the two rooms that does not have any mobs. The north exit leads to an armory, and the south exit leads to a room with many spellbooks, the room of a former arch mage. East leads further down the hall and west goes back to the great hall. */

inherit ROOM;

void create() {
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A long dark hallway");
 set_long(@ext Standing on a smooth floor above a smooth ceiling and surrounded by rough walls, none of which bearing anything besides the black stone they are fashioned of, you look upon this dark hallway. To your north and south you can see two archways that lead to what appear to be medium sized rooms, which probably belonged to the keep's former occupants. To your east and west you can make out a dark passage and a supposed intersection in the short distance respectively.
    0   
    |   
 0--@--0
    |
    0
ext);
set_smell("default", "The air smells very old and stale");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside13", "north");
add_exit(ROOMS+"inside14", "east");
add_exit(ROOMS+"inside15", "south");
add_exit(ROOMS+"inside4", "west");
set_items(([
({ "keep" }) : "The keep from within appears to be extremely dark and haunted.",
({ "rooms" }) : "The rooms to your north and south appear to be medium sized, and judging by their locations likely served residential purpose for former occupants of the keep.",
({ "hallway" }) : "This is a long dark hallway, with exits in all four directions.",
({ "intersection" }) : "What seems to be a four way intersection is barely seen to the west.",
({ "walls" }) : "The walls are fashioned of rough black stone and are completely plain.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning the ceiling and floor is very smooth.",
({ "passage" }) : "The passage appears very dark and can lead to anywhere.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon.",
({ "ceiling" }) : "The ceiling is well crafted of black stone and is very smooth.",
({ "archway" }) : "This is an archway that serves as an entrance to the adjoining room.",
({ "archways" }) : "These archways serve as entrances to the adjoining north and south rooms respectively.",
]));
}
