#include <std.h>
#include "../keep.h"

/* This room is the room containing the blue arcane orb, which serves a vital purpose in the black keep quest. There are no monsters in here initially, but when the player activates the orb by 'touching' it with the blue gem obtained from the basement jail in hand, a vicious silver dragon emerges blocking the exit. The crystal shard of life is revealed when the orb is shattered upon activation, and it then must be blessed by Lidfino at the pool of life before it can be used in forging the Legend Key at the Shadowforge. If a player tries to take the orb or touch it without them gem, the orb blasts them with energy and takes away 500-1000 hp. The only exit from this room is south back into the main west hall of the keep. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A triangle shaped room");
set_long(@ext The first thing you notice as you enter this room is that the curtain covered walls form a very large triangle with perfectly equal sides. A respectable amount of elegance is present due to the purple curtain suggesting this room is a chamber of importance. The ceiling is very smooth here, but unlike most other rooms in the keep the floor is not, instead it is fashioned of extremely rough black stone. In the direct center of this triangular shaped chamber is a cylindrical golden pedestal, standing about four feet off the ground.
  
    @
    |
    0
ext); 
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You hear mild noises of humming energy.");
add_exit(ROOMS+"inside27", "south");
ob = new(ITEM+"pedestal.c");
ob->move(this_object());
ob = new(ITEM+"blue_orb.c");
ob->move(this_object());
set_items(([
({ "curtain" }) : "This crackless curtain covers the entire wall and is dark purple in color.",
({ "stone" }) : "The stone fashioning the floor is black and extremely rough, while the stone comprising the ceiling is very smooth.",
({ "ceiling" }) : "The ceiling is well crafted of black stone and is very smooth.",
({ "room" }) : "This room is shaped like a perfect triangle. Elegant purple curtains completely cover the walls and a cylindrical golden pedestal extends upwards four feet from the floor. The only obvious exit from here is south.",
({ "chamber" }) : "This room is shaped like a perfect triangle. Elegant purple curtains completely cover the walls and a cylindrical golden pedestal extends upwards four feet from the floor. The only obvious exit from here is south.",
({ "walls" }) : "The walls are completely covered by a somewhat elegant purple curtain.",
({ "wall" }) : "The wall is completely covered by a somewhat elegant purple curtain.",
({ "floor" }) : "The floor of this room is extremely rough, built of thick black stone.",
({ "triangle" }) : "This entire room resembles the shape of a perfect equilateral triangle.",
({ "exit" }) : "The exit from this triangular shaped room is directly south.",
({ "side" }) : "This side of the triangle shaped room is covered by the purple curtain encompassing all three, and is exactly equal in length to the others.",
({ "sides" }) : "The three sides of the triangle shaped room are covered by a large crackless purple curtain, and are all exactly equal in length.",
({ "center" }) : "The center of this triangular room contains a pure golden pedestal extending four feet upwards from the rough floor.",
({ "keep" }) : "The keep from within appears dark and haunted.",
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
