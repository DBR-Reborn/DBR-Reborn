#include <std.h>
#include "../keep.h"

/* This is the third room of the western hallway of the black keep. In this room are three undead warriors, which should not pose much of a threat to a player who was able to kill the two vampiric demon and two undead warriors combo in the second west hall room. However, there is also one death soldier accompanying them. A death soldier is more powerful than both of the previous mobs, but not by a huge amount. The final room of the hallway lies down to the left, and the second room is to the east. North is the pool of divinity, one of the two disciple oriented rooms in the keep and a vital part of the keep quest. The south exit is blocked by a red door, and the blood stained key outside is required to open it. Inside is the abandoned room of a former demon master. */

inherit "/std/vault";

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A long dark hallway");
set_long(@ext Standing still on the smooth stone floor, you reluctantly gaze down both the dark passages leaving this room from the east and west. Turning around in a circle as you survey your location in the keep you can also see two archways among the walls also serving as exits, both in the north and south of the room respectively. The north archway is unobstructed and appears to lead to a room likely owned by a former keep occupant, but the south archway contains a well crafted red door blocking further access in that direction.
    0   
    |   
 0--@--0
    |
    0
ext);
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside26", "north");
add_exit(ROOMS+"inside27", "west");
add_exit(ROOMS+"inside28", "south");
add_exit(ROOMS+"inside11", "east");
set_door("red door", ROOMS+"inside28", "south", "blood key");
set_open("red door", 0);
set_locked("red door", 1);
set_lock_level("red door", 1000);
ob = new(MON+"death_soldier.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
set_items(([
({ "exits" }) : "The north exit leads to a medium sized room, while the south exit is blocked by a red door. The east and west exits lead down dark passages.",
({ "wall" }) : "The wall is fashioned of rough black stone and is completely plain.",
({ "passage" }) : "The passage appears very dark and can lead to anywhere.",
({ "passages" }) : "The passages leading east and west out of the room respectively appear very dark and can lead to anywhere.",
({ "hallway" }) : "This is a long dark hallway, with exits in all four directions.",
({ "walls" }) : "The walls are fashioned of rough black stone and are completely plain.",
({ "archway" }) : "This is an archway that serves as an entrance to the adjoining room.",
({ "archways" }) : "These archways serve as entrances to the adjoining north and south rooms respectively. A red door is blocking access beyond the south archway.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning the floor is very smooth.",
({ "room" }) : "The room to the north appears to be medium sized, and judging by its location likely served residential purpose for a former occupant of the keep.",
({ "keep" }) : "The keep from within appears to be extremely dark and haunted.",
({ "red door" }) : "This is a relatively bright red door, with a pentagram symbol above its center and a keyhole shaped like a horizontal line with a very small vertical line descending from its center is located on the middle right half.",
({ "door" }) : "This is a relatively bright red door, with a pentagram symbol above its center and a keyhole shaped like a horizontal line with a very small vertical line descending from its center is located on the middle right half.",
({ "north archway" }) : "This is an archway that serves as an entrance to the adjoining north room.",
({ "south archway" }) : "This is an archway that serves as an entrance to the adjoining south room. A red door is obstructing passage beyond it.",
]));
}
