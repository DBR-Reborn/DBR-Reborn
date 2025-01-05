#include <std.h>
#include "../keep.h"

/* This is the entrance of the basement level of the black keep accessible from the great hall. To prevent a possible 3 mob rooms in a row chain if a player comes down here from the entrance of the keep, there are no mobs present in this room. The staircase in this room leads back upstairs to the great hall, and the north passage leads closer toward the keep's grand library. */

inherit ROOM;

void create() {
::create();
set_property("light", 0);
set_property("indoors", 1);
set_short("A small stairway room");
set_long(@ext This relatively small room, with a somewhat low ceiling and rough stone walls, is the home to a well built circular staircase located in the rooms southern end. Apart from that, nothing else is present in this room except an empty torch bearing on each wall. Looking to the north you see a passage which is emitting relatively bright light. It appears to be the only way to go if you do not want to return upstairs.
    0   
    |   up   
    @
ext);
set_smell("default", "The air smells very old and stale");
set_listen("default", "You hear footsteps and faint voices coming from the north.");
add_exit(ROOMS+"inside16", "north");
add_exit(ROOMS+"inside4", "up");
set_items(([
({ "light" }) : "The light emanating from the passage appears relatively bright to the naked eye.",
({ "southern end" }) : "A relatively circular staircase leading upstairs begins in this section of the room.",
({ "wall" }) : "The wall is fashioned of rough black stone. An empty torch bearing is bolted into it.",
({ "keep" }) : "Light is seen from this room, unlike other rooms of the keep which appear extremely dark and haunted.",
({ "room" }) : "This room has a somewhat low ceiling, a staircase leading up at its south end and a somewhat illuminated passage leading out from the north.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning the ceiling is very smooth.",
({ "walls" }) : "The walls are fashioned of rough black stone. An empty torch bearing is bolted on each.",
({ "bearing" }) : "This is an empty torch bearing bolted into the wall.",
({ "passage" }) : "The passage provides a relatively bright light coming from a room beyond.",
({ "ceiling" }) : "The ceiling appears to be rather low in this room. It is well crafted of black stone and is very smooth.",
({ "staircase" }) : "The staircase is circular and leads up.",
]));
add_pre_exit_function("up", "go_up");
}

int go_up() {
write("You walk up the somewhat circular staircase to the upper floor.");
return 1;
}
