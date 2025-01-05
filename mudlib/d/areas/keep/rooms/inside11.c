#include <std.h>
#include "../keep.h"

/* This is the second room of the black keep's western hallway. This room contains two undead warriors and two vampiric demons as one of the two mob rooms of the four room hall. The hallway continues both east and west, and to the north and south are two rooms owned by the keeps former occupants. The north room is covered with a pulsing dark shadow cloud, and the south room leads to a cloning chamber. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A long dark hallway");
set_long(@ext You see two identical archways leading out of this rough walled, plain floored room from the north and south exits, and two identical passages to the east and west also serving as exits. The archways both lead to rooms which judging by what you can see appear to have served accomodation purposes for the keep's former occupants. The two passages perpendicular to the archways both contain no noticeable features and disallow vision into the respective rooms beyond.
    0   
    |   
 0--@--0
    |
    0
ext);
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside18", "north");
add_exit(ROOMS+"inside19", "west");
add_exit(ROOMS+"inside20", "south");
add_exit(ROOMS+"inside6", "east");
ob = new(MON+"vampiric_demon.c");
ob->move(this_object());
ob = new(MON+"vampiric_demon.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
set_items(([
({ "room" }) : "This room contains exits in all four directions, two to medium sized rooms and two down dark passages.",
({ "exits" }) : "The north and south exits lead to medium sized rooms, and the east and west exits lead down dark passages.",
({ "wall" }) : "The wall is fashioned of rough black stone and is completely plain.",
({ "passage" }) : "The passage appears very dark and can lead to anywhere.",
({ "passages" }) : "The passages leading east and west out of the room respectively appear very dark and can lead to anywhere.",
({ "hallway" }) : "This is a long dark hallway, with exits in all four directions.",
({ "walls" }) : "The walls are fashioned of rough black stone and are completely plain.",
({ "archway" }) : "This is an archway that serves as an entrance to the adjoining room.",
({ "archways" }) : "These archways serve as entrances to the adjoining north and south rooms respectively.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning the floor is very smooth.",
({ "rooms" }) : "The rooms to your north and south appear to be medium sized, and judging by their locations likely served residential purpose for former occupants of the keep.",
({ "keep" }) : "The keep from within appears to be extremely dark and haunted.",
]));
}
