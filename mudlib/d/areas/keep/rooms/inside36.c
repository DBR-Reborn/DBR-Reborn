#include <std.h>
#include "../keep.h"

/* This is the green arcane orb room of the black keep, a vital room in the black keep quest. There are no monsters initially present in this room, but a powerful Silver Dragon blocking the exit appears once a player has 'touched' the orb with the green gem from mount nelfton in their possession. If the player does not have the green gem, they will lose 500-1000 hp by touching it, or trying to take it regardless if the gem is present or not. When the orb is activated and shattered by touching it, the Crystal Shard of Terra is revealed in the room. The shard must be taken to the paladin temple room and offered to Sacrel by a paladin to bless it before it can be used in forging the legend key. The only exit is south into the main hall of the keeps east wing. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A pentagon shaped room");
set_long(@ext A crackless purple curtain completely covers all five walls of this somewhat large mid to high ceiling pentagon shaped room. The curtain suggests due to the amount of elegance it provides that this room is one of importance in some manner. The floor unlike most others in the keep is extremely rough, fashioned of thick black stone. In its center stands a four foot tall cylindrical pedestal fashioned completely of solid gold.

    @
    |
    0
ext);
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You hear mild noises of humming energy.");
add_exit(ROOMS+"inside30", "south");
ob = new(ITEM+"pedestal.c");
ob->move(this_object());
ob = new(ITEM+"green_orb.c");
ob->move(this_object());
set_items(([
({ "curtain" }) : "This crackless curtain covers the entire wall and is dark purple in color.",
({ "floor" }) : "The floor of this room is extremely rough, built of thick black stone.",
({ "walls" }) : "The walls are completely covered by a somewhat elegant purple curtain.",
({ "wall" }) : "The wall is completely covered by a somewhat elegant purple curtain.",
({ "ceiling" }) : "The ceiling is well crafted of black stone and is very smooth.",
({ "room" }) : "This room is somewhat larged and shaped like a perfect pentagon, with a crackless purple curtain covering all five walls. A golden pedestal rests in the center extending about four feet up from the floor, and the only obvious exit is south.",
({ "exit" }) : "The exit from this pentagon shaped room is directly to the south.",
({ "pentagon" }) : "The pentagon shape of this room is that of perfection.",
({ "keep" }) : "The keep from within appears dark and haunted.",
({ "stone" }) : "The stone fashioning the floor is black and extremely rough, while the stone comprising the ceiling is very smooth.",
({ "center" }) : "The center of the room contains a pure golden pedestal extending four feet up from the rough floor.",
]));
add_pre_exit_function("south", "go_south");
}

int go_south() {
if(present("silver dragon")) {
write("The Silver Dragon spreads its huge wings and roars at you as it blocks your exit.");
return 0;
}
else
return 1;
}
