#include <std.h>
#include "../keep.h"

/* This is the assassins quarters of the black keep. There are no monsters present in this room for the purpose of giving it a more abandoned feel. There is an oak table standing here with a contract on it, impaled by a death dagger. To get the contract, which is a quest item required for part of the sequence to get the green gem for the green arcane orb, the player must get spellups from several guilds to amass a 400 strength stat. This is done to again stress the importance of partying to do the quest. The only exit from this room is south back into the keep's east wing. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("An assassin's quarters");
set_long(@ext Judging by the dagger impaled into an oak table through a piece of paper that appears to be a contract of some sorts at the north end of the room, you quickly infer that this medium sized room likely belonged to an assassin before the keep was overtaken. Beside the table and what is on its top, nothing else is present in the room, not even a chair for the table. There is absolutely no decoration on the walls, nor anything stray lying on the floor.
  
    @
    |
    0
ext);
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You dont hear a sound.");
add_exit(ROOMS+"inside14", "south");
ob = new(ITEM+"oak_table.c");
ob->move(this_object());
ob = new(ITEM+"death_dagger.c");
ob->move(this_object());
ob = new(ITEM+"contract1.c");
ob->move(this_object());
set_items(([
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning the floor is very smooth.",
({ "wall" }) : "The wall is fashioned of rough black stone and is completely plain.",
({ "walls" }) : "The walls are fashioned of rough black stone and are completely plain.",
({ "paper" }) : "The piece of paper impaled into the oak table by a vicious looking dagger appears to be a contract of some kind.",
({ "north end" }) : "An oak table sits in this part of the room, with a dagger impaled through it and a piece of paper that resembles a contract.",
({ "room" }) : "This is a medium sized room, with an oak table containing a piece of paper with a dagger impaled through it at the north end, and the exit to the south.",
({ "keep" }) : "The keep from within appears very dark and haunted.",
({ "top" }) : "The top of the oak table contains a paper which looks very much like an assassination contract, and a mean dagger impaled directly through it and the table itself.", 
({ "exit" }) : "The unobstructed exit from this room is located in its south end.",
({ "south end" }) : "The exit from the room is located here, directly opposite from the oak table and what rests on its top.",
]));
}
