#include <std.h>
#include "../keep.h"

/* This is a medium to large sized room in the east wing of the black keep. Present in here are two warlocks, intended to introduce players into the concept of fighting more than one of the powerful summoners. Also present in the rooms center is a statue of an open palm, which recieves Lidfino's offerings. That offering for the quest is the red gem, which is given if a disciple immerses the holy soul in the pool of life at the other end of the keep. To make the quest more difficult, the player must look at the statue to see the gem is there, they cannot just wander around looking for it. The player once they see it can 'get gem'. The only exit from here is south back into the east wing hall. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A relatively spacious room");
set_long(@ext This room appears somewhat larger in size than most others in the keep. Despite this however there are no recognizable features distinguishing the walls nor floor from a completely barren room of smaller size. Present in this room though is a four foot tall white statue of a horizontally open palm and part of an arm holding it up off the floor. Perhaps the shape or the color contains hidden meaning.
   
    @
    |
    0
ext);
set_smell("default", "The air smells noticeably pure.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside22", "south");
ob = new(MON+"warlock.c");
ob->move(this_object());
ob = new(MON+"warlock.c");
ob->move(this_object());
ob = new(ITEM+"palm_statue1.c");
ob->move(this_object());
set_items(([
({ "walls" }) : "The walls are fashioned of rough black stone and are completely plain.",
({ "wall" }) : "The wall is fashioned of rough black stone and is completely plain.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon.",
({ "room" }) : "This is a rather large room, void of decoration save for the four foot tall white statue in the center of an open palm coming from part of an arm. The only visible exit is south.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning the floor is very smooth. The palm statue in the center of the room is built of stone bright white.",
({ "exit" }) : "The exit from this somewhat large room is to your south.",
({ "arm" }) : "The arm of the statue holding the palm is about three feet long from the floor up.",
({ "keep" }) : "The keep from within appears to be extremely dark and haunted.",
({ "palm" }) : "The palm on the statue is open horizontally and is almost a foot tall. It stands atop a three foot stone arm.",
]));
}

void reset() {
::reset();
if(present("palm statue")) {
return;
}
}
void init() {
::init();
if(present("palm statue 2")) {
present("palm statue 2")->remove();
}
}
