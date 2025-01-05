#include <std.h>
#include "../keep.h"

/* This is the entrance room of the black keep. Present in this room are two undead warriors, which are mobs somewhat comparable to the snakes outside the keep, only with a more offense and less defense balance. They are designed to test the player if he did not fight the snakes outside to see whether or not they are prepared to go further. If a player could easily kill the snakes, he/she would have no trouble here. The north exit leads further inside the keep, and the out exit leads back outside to the misty field. */

inherit "/std/vault";

int a;

void init() {
::init();
if(a<1) {
write("%^BOLD%^%^GREEN%^Necromancer appears from the shadows.%^RESET%^");
write("Necromancer says in Common: %^MAGENTA%^Welcome adventurers. Enjoy yourself inside the structure, owned by the forces of Owedquar.%^RESET%^");
write("%^BOLD%^%^GREEN%^Necromancer fades into the shadows.%^RESET%^");
return;
}
}

void create() {
object ob;
::create();
set_property("light", 0);
set_property("indoors", 1);
set_short("The black entryway");
set_long(@ext As you stand within the entryway of the enormous black keep, you feel a very strange premonition. Nearly everything within the room is pitch black, including the ceiling, walls, floor, and the gate leading outside. The only things in this room with any type of color is an old broken grey door laying against the left wall.
    0   
    |   
    @
    
    out
ext);
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside2", "north");
add_exit(ROOMS+"outsidegate", "out");
set_door("gate", ROOMS+"outsidegate", "out", "no key door");
set_open("gate", 1);
set_locked("gate", 0);
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
set_items(([
({ "entryway" }) : "The entryway of the black keep consists of a pitch black ceiling, floor, and walls.", 
({ "bearing" }) : "This is an empty torch bearing bolted into the wall.",
({ "keep" }) : "The keep from within appears to be extremely dark and haunted.",
({ "ceiling" }) : "The ceiling is well crafted of black stone and is very smooth.",
({ "walls" }) : "The walls are somewhat rough, with an empty torch bearing on each. There is a broken grey door leaning against the left wall.",
({ "door" }) : "This door, somewhat grey in color, appears to be a beaten and broken vault door.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon.",
({ "gate" }) : "The gate leading outside is black with two dragons, one on each half, facing each other.",
({ "dragons" }) : "The black dragons on the gate stare endlessly upon one another, each covering one half of the gate itself.",
({ "room" }) : "The room itself is almost completely black, with the exception of the broken grey door on the left wall.",
({ "left wall" }) : "A broken grey door leans against this rough black wall.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning ther ceiling and floor is very smooth.",
]));
a = 0;
add_pre_exit_function("north", "go_north");
}

int go_north() {
a++;
return 1;
}
