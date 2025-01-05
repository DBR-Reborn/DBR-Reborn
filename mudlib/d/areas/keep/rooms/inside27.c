#include <std.h>
#include "../keep.h"

/* This is the ending room of the west hall, the furthest from the center of the keep. There are no monsters present here, for two of the four rooms of the west hallway have them. The east exit from here leads back into the center rooms of the hallway, while the north and south exits lead to medium sized rooms. The north room is the room containing the green arcane orb, which is required for the quest, and the south room is a warlocks quarters, containing books pertaining to the guild. */

inherit ROOM;

void create() {
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("The end of a dark hallway");
set_long(@ext If the large shattered lantern on the west wall was any indication, it can be said that most of the light provided in this half of the keep before its fall was generated from this location. The wall containing the broken object of light is very rough, but the floor remains smooth and appears to have been frequently traversed. Looking to your direct north and south you see two open archways which appear to lead to medium sized rooms. To the east you can see nothing but darkness down the long passage.
    0   
    |   
    @--0
    |
    0
ext);
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside33", "north");
add_exit(ROOMS+"inside34", "south");
add_exit(ROOMS+"inside19", "east");
set_items(([
({ "lantern" }) : "The lantern on the west wall is badly shattered. It is impossible to light.",
({ "west wall" }) : "The wall is fashioned of rough black stone and has a large badly smashed lantern bolted onto its center.",
({ "wall" }) : "The wall is fashioned of rough black stone and has a large badly smashed lantern bolted onto its center.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning the floor is very smooth.",
({ "keep" }) : "The keep from within appears very dark and haunted.",
({ "passage" }) : "The passage appears very dark and can lead to anywhere.",
({ "archway" }) : "This is an archway that serves as an entrance to the adjoining room.",
({ "archways" }) : "These archways serve as entrances to the north and south rooms respectively.",
({ "rooms" }) : "The rooms beyond the archways are difficult to completely make out but appear medium sized.",
({ "hallway" }) : "This appears to be the end of a hallway. It appears to lead backwards down the dark passage to the east.",
({ "center" }) : "The center of the west wall contains a relatively large well destroyed lantern.",
]));
}
