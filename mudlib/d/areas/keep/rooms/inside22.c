#include <std.h>
#include "../keep.h"

/* This is the third room of the east hall of the black keep. There are no mobs in this room for the sole purpose of preventing the hall from looking as if it is a mob farm. The hallway continues to its fourth and final room to the east, and to the west it goes back to the second room. North lies an enormous open palm, homage to a divine god. South is a dirty and destroyed room of great former elegance, the residence of a former paladin. */ 

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A long dark hallway");
set_long(@ext You see two archways, one facing the other, as you look to the north and south upon entering the room. Looking through these exits you can see medium sized rooms which you infer likely belonged to former occupants of the keep. As you move to look to the east and west, viewing completely plain walls as you turn your head. you see nothing but dark passages and the smooth stone floor also visible throughout the entire room leading into them.
    0   
    |   
 0--@--0
    |
    0
ext);   
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside29", "north");
add_exit(ROOMS+"inside30", "east");
add_exit(ROOMS+"inside31", "south");
add_exit(ROOMS+"inside14", "west");
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
