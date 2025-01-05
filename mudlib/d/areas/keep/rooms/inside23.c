#include <std.h>
#include "../keep.h"

/* This is the Mace of the Lord worship room of the black keep. There are three death soldiers present in here, intended to give players the feel of fighting multiples of the mob which casts many curse magics. Also in this room is a large statue of Taul. The statue serves no special purpose but to act as decoration to let the player know where he is should be not look at the description of the room closely enough. This room serves a purpose late in the areas quest. The crystal shard of power, obtained from activating the red arcane orb, is offered to Taul here by a mace. When the prayer is heard the shard will recieve the blessing required to use it in the forging of the legend key. */ 

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("The room of a grand statue");
set_long(@ext A majestic statue of the God of War, Taul himself, stands ten feet tall facing you directly as you enter this room from the north. Two banners carrying the insignia of the Mace of the Lord hang covering a great deal of the east and west walls, and a large red and black carpet lays on the smooth floor. The elegance of the room however appears rotted, likely due to long passage of time.
    0   
    |   
    @
ext); 
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside14", "north");
ob = new(MON+"death_soldier.c");
ob->move(this_object());
ob = new(MON+"death_soldier.c");
ob->move(this_object());
ob = new(MON+"death_soldier.c");
ob->move(this_object());
ob = new(ITEM+"taul_statue.c");
ob->move(this_object());
set_items(([
({ "room" }) : "A red and black carpet sits on the floor in front of a huge statue of the god Taul, and two banners with his insignia hang on the walls. The only noticeable exit from the room is north.",
({ "banner" }) : "This is a large banner carrying the insignia of the Mace of the Lord. It hangs from the wall and appears somewhat rotted due to age.",
({ "banners" }) : "The two banners hanging on the west and east walls carry the insignia of the Mace of the Lord. They appear somewhat rotted due to age.",  
({ "insignia" }) : "The insignia present on the banners hanging from the walls is that of the Mace of the Lord, lifelong devoted followers of Taul. It is a large equal sided steel cross which appears to have bladed edges.",
({ "armour" }) : "The armour mold on the statue of Taul is painted a terribly shiny silver, and looks extraordinarily well crafted.",
({ "mace" }) : "The huge mace molded into and grasped by both hands of the large statue appears very real and lethal. At the size and thickness of a large man it is held diagonally across the statue's body.",
({ "carpet" }) : "The carpet on the floor in front of the statue is bright red and black, but somewhat dirty and rotted.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon. A relatively large red and black carpet rests on it in front of the large statue of Taul.",
({ "walls" }) : "The rough black stone walls to the east and west carry huge banners which cover them by more than half. The back wall in the south is completely plain.", 
({ "back wall" }) : "The wall in the back of the room to the south is fashioned of rough black stone and is completely plain.",
({ "west wall" }) : "The rough black stone wall in the west of the room contains a very large banner, covering more than half of its available space.",
({ "east wall" }) : "The rough black stone wall in the east of the room contains a very large banner, covering more than half of its available space.",
({ "wall" }) : "The wall before you is fashioned of rough black stone, and is well constructed.",
({ "exit" }) : "The exit from this room of worship is located in the north.",
]));
}
