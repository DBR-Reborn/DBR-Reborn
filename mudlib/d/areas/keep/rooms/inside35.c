#include <std.h>
#include "../keep.h"

/* This is the basement room which serves as the entrance to the black keep jail. It is accessible only from the southern demon master summoning room in the west wing, when a player pushes the stone button found after moving the corpses enough times. This room contains four death soldiers, the equivalent of the forced battle in the clone statues room to offer the same challenge level to a player as a warning worse battles are ahead. To open the jail cell present blocking the south exit into the jail, the rusted key hidden behind the cracked curtains in the red arcane orb room on the second floor is required. The other exit from this room is back upstairs. */

inherit "/std/vault";

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A filthy passage");
set_long(@ext This room, with a relatively low ceiling which almost requires you to crouch, is incredibly filthy. A horrid stench coming from beyond the bars of the jail cell to the south almost causes you to faint as do the sights before you. Both the smooth floor, the rough walls, and the stairs leading upstairs are covered with dried blood and rotting bones. You dont have to think twice before realizing something extremely terrible happened here, and by the looks of things not too long ago.
       
        up   
    @
    |
    0
ext);
set_smell("default", "The air smells absolutely horrid and disgusting.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside28", "up");
add_exit(ROOMS+"insidejail", "south");
set_door("jail cell", ROOMS+"insidejail", "south", "old key");
set_open("jail cell", 0);
set_locked("jail cell", 1);
set_lock_level("jail cell", 1000);
ob = new(MON+"death_soldier.c");
ob->move(this_object());
ob = new(MON+"death_soldier.c");
ob->move(this_object());
ob = new(MON+"death_soldier.c");
ob->move(this_object());
ob = new(MON+"death_soldier.c");
ob->move(this_object());
set_items(([
({ "room" }) : "This is a very disgusting room, with nothing present but dried blood and rotting bones. The only exits are back upstairs and south through a jail cell.",
({ "exits" }) : "The exits from this sickening room are south through a jail cell and up stone stairs to the next level up.",
({ "ceiling" }) : "The ceiling is well crafted of black stone and is very smooth.",
({ "stone" }) : "The stone comprising the walls and stairs present in the room is black and extremely rough, while the stone fashioning the ceiling and floor is very smooth.",
({ "bars" }) : "The bars on the jail cell are noticeably rusted, yet appear very sturdy.",
({ "cell" }) : "The jail cell serving as the exit from this sickening room is located to the south, and by appearance is heavily rusted.",
({ "jail cell" }) : "The jail cell serving as the exit from this sickening room is located to the south, and by appearance is heavily rusted.",
({ "rust" }) : "The rust on the jail cell is very thick, signifying great age.",
({ "sights" }) : "The sights of this room include nothing but dried blood and rotting bones, as well as a rusted jail cell to the south.",
({ "floor" }) : "The floor, black in appearance and covered with dried blood and rotting bones, appears to have been heavily traveled upon.",
({ "blood" }) : "The blood covering the floor and walls is extremely old and dry.",
({ "bones" }) : "The bones present on the floor appear to be steadily rotting away.",
({ "stairs" }) : "The railless stairs are fashioned of rough black blood soaked stone and lead up.",
({ "walls" }) : "The black stone walls, despite being completely plain of design, are smeared in dried blood.",
({ "wall" }) : "The black stone wall, despite being completely plain of design, is smeared in dried blood.",
]));
add_pre_exit_function("up", "go_up");
}

int go_up() {
write("You walk up the stone steps to the main level.");
return 1;
}
