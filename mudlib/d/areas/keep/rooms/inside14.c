#include <std.h>
#include "../keep.h"

/* This is the black keep's second eastern hall room. Residing in this room are two vampiric demons and two death soldiers. This is to signify to the player this this half of the keep is far more dangerous than the other half. The hallway continues both to the east and west, and to the north and south are two rooms that once belonged to the keeps former occupants. The north room is barren save for a table and a bunch of daggers, a former invisible daggers room, and the south room contains a huge statue of Taul, a maces old dwelling. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A long dark hallway");
set_long(@ext As dark passages serve as exits from this smooth floored room to the east and west directions, two archways also lead out of here to the north and south respectively. Small to medium sized rooms which likely belonged to the keep's former residents can be seen through these two exits. However, virtually nothing can be seen down the east and west passages, save for the completely plain black stone walls that also compose the rest of the room.
    0   
    |   
 0--@--0
    |
    0
ext); 
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside21", "north");
add_exit(ROOMS+"inside22", "east");
add_exit(ROOMS+"inside23", "south");
add_exit(ROOMS+"inside7", "west");
ob = new(MON+"vampiric_demon.c");
ob->move(this_object());
ob = new(MON+"vampiric_demon.c");
ob->move(this_object());
ob = new(MON+"death_soldier.c");
ob->move(this_object());
ob = new(MON+"death_soldier.c");
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
