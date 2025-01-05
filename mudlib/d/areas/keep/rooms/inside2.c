
#include <std.h>
#include "../keep.h"

/* This is the second room of the entrance hall of the black keep. There are no monsters in this room, to prevent the entire three room entrance hall from having monsters and making the area look like it has too many mobs. The south exit leads back to the keep entrance room, and going north ends up at the entrance halls third and final room. */

inherit ROOM;

void create() {
::create();
set_property("light", 0);
set_property("indoors", 1);
set_short("The entrance hall");
set_long(@ext You now stand between two broken grey doors, one in front of and one behind you. Both doors are leaning against the left wall. You see very dim light coming from the room behind you, and no light whatsoever coming from further inside the keep. An empty torch bearing is also present on each wall.
    0   
    |   
    @
    |
    0
ext);
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside3", "north");
add_exit(ROOMS+"inside1", "south");
set_items(([
({ "light" }) : "The light coming from the room behind you is extremely dim, likely coming from the outside.",
({ "doors" }) : "The two doors, somewhat grey in color, appear to be beaten and broken vault doors.",
({ "bearing" }) : "This is an empty torch bearing bolted into the wall.",
({ "keep" }) : "The keep from within appears to be extremely dark and haunted.",
({ "walls" }) : "The walls are fashioned on rough black stone. An empty torch bearing is bolted on each, and two broken grey doors are leaning against the left wall.",
({ "left wall" }) : "Two broken grey doors lean against this wall fashioned of rough black stone.",
({ "wall" }) : "The wall is fashioned of rough black stone. An empty torch bearing is bolted on it",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough.",
({ "door" }) : "This door, somewhat grey in color, appears to be a beaten and broken vault door.",
({ "door 2" }) : "This door, somewhat grey in color, appears to be a beaten and broken vault door.",
]));
}
