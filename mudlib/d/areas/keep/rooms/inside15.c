#include <std.h>
#include "../keep.h"

/* This is the arch mage chamber of the black keep, a room that once belonged to a member of that guild before the keep's takeover by Owedquar. There is one monster in this room, a dark robed warlock. It is here alone as somewhat of a test to see whether or not the player is prepared to face them, as many more lurk further in the east wing. Present in this room are four spellbooks, each of which give information pertaining to a certain aspect of the arch mage guild. There are no immediate secrets in this room, but the white book is required to proceed further in the keep's quest, for it is the book the librarian in the basement is seeking. The only exit from this room is to the north, which leads back into the main hallway of the keep's east wing. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A moderately decorated room");
set_long(@ext Several pieces of well designed art cover the black stone walls, and somewhat elegant carpets cover the smooth floor. In the southern end of the room, opposite from the exit, sits a large anchored table with several decent sized books stacked on top of each other, and a heavily worn chair under it. Using mental deduction, you believe this room once belonged to a scholar of some sorts, likely one that studied magic.
    0   
    |   
    @
ext);
set_smell("default", "The air smells a mixture of fresh and stale.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside7", "north");
ob = new(MON+"warlock.c");
ob->move(this_object());
ob = new(ITEM+"green_book.c");
ob->move(this_object());
ob = new(ITEM+"brown_book.c");
ob->move(this_object());
ob = new(ITEM+"purple_book.c");
ob->move(this_object());
ob = new(ITEM+"white_book.c");
ob->move(this_object());
ob = new(ITEM+"table.c");
ob->move(this_object());
/*
ob = new("/std/tailwind/obj/chair.c");
ob->move(this_object());
*/
set_items(([
({ "carpets" }) : "The carpets covering the floor are very well designed and make the room look considerably more welcoming.",
({ "walls" }) : "The walls are fashioned of rough black stone and contain magnificent art.",
({ "art" }) : "This is indeed very well crafted art. It covers all the walls present in this room and seemingly makes them come alive.",
({ "room" }) : "The room contains a table, chair, and several books at the southern end, beautiful carpets and art on the walls and floor, and the exit in the northern end.",
({ "southern end" }) : "An anchored table, worn chair, and several books are located here.",
({ "northern end" }) : "The exit from this slightly elegant room is positioned here.",
({ "books" }) : "Many books of varying colors sit stacked atop the table.",
({ "exit" }) : "The exit from this room is located in its northern end.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning the floor is very smooth.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon. Many well designed carpets lay here on it seemingly giving it life.",
]));
}
