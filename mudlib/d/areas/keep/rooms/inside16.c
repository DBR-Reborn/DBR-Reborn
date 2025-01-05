#include <std.h>
#include "../keep.h"

/* This is the second room of the black keep basement level. Present in this room are two vampiric demon mobs, a similar challenge than the one vampiric demon and three undead warriors in the great hall room. This room is the dividing room between the grand library and the basement entry room with the staircase leading upstairs to the great hall. The library is directly to the north, and the entry room to the south. There is also a secret axe located in this room, which can be found if the player is highly observant of the room description and pushes in the protruding brick on the left wall containing the empty torch bearing.  */

inherit ROOM;

int found;
object ob2;

void create() {
object ob;
::create();
found=0;
set_property("light", 0);
set_property("indoors", 1);
set_short("A bright narrow hallway");
set_long(@ext A decent amount of light strikes you from the north while looking about the significantly narrow hallway. You can very easily make out the two empty torch bearings bolted on bricks protruding from both walls, as well as the plain ceiling and dust covered floor. Looking to the north you see the light illuminating the room, coming from what appears to be a library of some sort. You can also faintly see a circular staircase leading upstairs at the south end of the hallway using the allotted illumination.
    0   
    |   
    @
    |
    0
ext);
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You hear footsteps sounding as if they are merely a few feet away, as well as voices coming from the north.");
add_exit(ROOMS+"insidelibrary", "north");
add_exit(ROOMS+"inside8", "south");
ob = new(MON+"vampiric_demon.c");
ob->move(this_object());
ob = new(MON+"vampiric_demon.c");
ob->move(this_object());
set_items(([
({ "left wall" }) : "The wall is fashioned of rough black stone. A somewhat loose brick containing an empty torch bearing on its front is protruding from it.",
({ "right wall" }) : "The wall is fashioned of rough black stone. A well molded brick containing an empty torch bearing on its front is protruding from it.",
({ "illumination" }) : "The light coming directly from the north provides adequate illumination for this hallway.",
({ "bearing" }) : "This is an empty torch bearing bolted into a brick protruding from the wall.",
({ "bearings" }) : "Two empty torch bearings are bolted into protruding bricks, one from each wall.",
({ "exits" }) : "The exits from this room are located to both the north and south.",
({ "light" }) : "The light coming from the north room is very bright, illuminating this hallway quite well.",
({ "ceiling" }) : "The ceiling appears to be rather low in this room. It is well crafted of black stone and is very smooth.",
({ "staircase" }) : "The staircase seen faintly to the south appears circular and leads up.",
({ "walls" }) : "The walls are fashioned of rough black stone. An empty torch bearing is bolted on a brick protruding from each.",
({ "bricks" }) : "Two bricks protrude from the walls of the room, one located on both the left and right walls respectively. Bolted on each brick is an empty torch bearing.", 
({ "right brick" }) : "This brick protrudes directly out of the right wall of the room with a bolted torch bearing on its front. It appears to be molded very well as part of the wall itself and likely will not budge if touched.",
({ "left brick" }) : "This brick protrudes directly out of the left wall of the room with a bolted torch bearing on its front. Looking closely at it you can see that it is relatively loose from the rest of the wall.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning both the ceiling and dusty floor is very smooth.",
({ "hallway" }) : "This is a very narrow hallway, with exits located to the north and south and plain without decoration save for empty torch bearings on protruding bricks, one coming from each wall.",
({ "south end" }) : "You can see a faint circular staircase in the room beyond here to the south.",
({ "north end" }) : "What appears to be a library is seen in the room to the north, along with the light brightening this hallway.",
({ "library" }) : "What appears to be a library is seen in the room to the north, along with the light brightening this hallway.",
({ "north room" }) : "What appears to be a library is seen in the room to the north, along with the light brightening this hallway.",
({ "south room" }) : "You can see a faint circular staircase in the room beyond here to the south.",
({ "floor" }) : "The floor, while black in appearance and covered in dust, is extremely smooth and appears to have been heavily traveled upon.", 
({ "dust" }) : "Dust covers most of the floor beneath your feet, suggesting either this room has been traveled through very frequently or has been abandoned for ages.",
]));
}

void init() {
::init();
add_action("read_func", "push");
}

int read_func(string str) {
if(!str || str!="left brick") {
notify_fail("What?");
return 0;
}
if(found<1) {
write("You push the left brick and it quickly falls into the wall. Looking through the small hole created, you see a worn black axe a builder likely lost during the creation of the structure.");
ob2 = new(WEAP+"black_axe.c");
ob2->move(this_object());
found=1;
return 1;
}
}
