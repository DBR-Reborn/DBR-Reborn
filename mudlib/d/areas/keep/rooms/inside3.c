
#include <std.h>
#include "../keep.h"

/* This is the second room of the entrance hall of the black keep. There are no monsters in this room, to prevent the entire three room entrance hall from having monsters and making the area look like it has too many mobs. The south exit leads back to the keep entrance room, and going north ends up at the entrance halls third and final room. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", 0);
set_property("indoors", 1);
set_short("The entrance hall");
set_long(@ext Extremely low levels of light, in fact almost non-existant amounts, strike this room from the south as you look around. From what you can see, two battered grey doors are leaning against the left wall, and one empty torch bearing tightly bolted into both walls. You can also see somewhat of an intersection in the room to the north.
    0   
    |   
    @
    |
    0
ext);  
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside4", "north");
add_exit(ROOMS+"inside2", "south");
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
set_items(([
({ "light" }) : "The light coming from the south is present, but virtually non-existant for illumination purposes.",
({ "intersection" }) : "What seems to be a four way intersection is barely seen to the north.", 
({ "doors" }) : "The two doors, somewhat grey in color, appear to be beaten and broken vault doors.",
({ "bearing" }) : "This is an empty torch bearing bolted into the wall.",
({ "keep" }) : "The keep from within appears to be extremely dark and haunted.",
({ "walls" }) : "The walls are fashioned of rough black stone. An empty torch bearing is bolted on each, and two broken grey doors are leaning against the left wall.",
({ "left wall" }) : "Two broken grey doors lean against this wall fashioned of rough black stone.",
({ "wall" }) : "The wall is fashioned of rough black stone. An empty torch bearing is bolted on it",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough.",
({ "door" }) : "This door, somewhat grey in color, appears to be a beaten and broken vault door.",
({ "door 2" }) : "This door, somewhat grey in color, appears to be a beaten and broken vault door.",
]));
}
