#include <std.h>
#include "../keep.h"

/* This is the only entrance of the black keep's second floor. Present in this room is one shadow knight, the most powerful of the keep's common monsters. It is located here as a warning of the difficulty of this floor, and is the only shadow knight you can fight without having the key to open the door in this room to go further. The staircase leads back downstairs, and west past the door leads to the second floor intersection. */

inherit "/std/vault";

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A small stairway room");
set_long(@ext This is a somewhat small smooth floored room, containing a staircase in the northern end leading downstairs. There is an empty torch bearing present on both the south and east walls, and in the west section of the room there is a well built blue door blocking access to what lies beyond.
  
 0--@
        down 
ext);
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You hear an evil voice echoing in your head.");
add_exit(ROOMS+"inside17", "west");
add_exit(ROOMS+"inside5", "down");
set_door("blue door", ROOMS+"inside17", "west", "blue key");
set_open("blue door", 0);
set_locked("blue door", 1);
set_lock_level("blue door", 1000);
ob = new(MON+"shadow_knight.c");
ob->set_property("aggressive", 0);
ob->move(this_object());
set_items(([
({ "walls" }) : "The walls are fashioned of rough black stone. An empty torch bearing is bolted on each.",
({ "downstairs" }) : "You cannot effectively make out the downstairs beyond the staircase without leaving the room on it.",
({ "room" }) : "The room is relatively small with a smooth floor, a staircase in the northern end, and a door in the west section.",
({ "west section" }) : "There is a well built blue door located here blocking access on this floor beyond the room.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon.",
({ "staircase" }) : "The staircase descends downstairs in a straight formation.",
({ "door" }) : "The door is extremely well contructed, with a pentagram symbol above its center and an oddly shaped keyhole on the middle right.",
({ "blue door" }) : "The blue door is extremely well contructed, with a pentagram symbol above its center and an oddly shaped keyhole on the middle right.",
({ "pentagram" }) : "The pentagram on the door protrudes and looks well designed.",
({ "keyhole" }) : "The keyhole looks as if it requires a key with three prongs in a triangular formation.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough.",
({ "east wall" }) : "The east wall is fashioned of rough black stone. An empty torch bearing is bolted into it.",
({ "south wall" }) : "The south wall is fashioned of rough black stone. An empty torch bearing is bolted into it.",
({ "northern end" }) : "A straight set of stairs leading down begins here.",
({ "bearing" }) : "This is an empty torch bearing bolted into the wall.",
]));
add_pre_exit_function("down", "go_down");
}

int go_down() {
write("You descend the staircase to reach the lower floor.");
return 1;
}
