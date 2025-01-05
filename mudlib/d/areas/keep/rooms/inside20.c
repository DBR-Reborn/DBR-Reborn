#include <std.h>
#include "../keep.h"

/* This room is the clone statues room of the black keep. In this room the player if he/she is participating in the areas quest can obtain the blue key required to access the main part of the second floor. There are no mobs initially present in the room, but four death soldiers which block the exit out appear if the player opts to get the blue key. There are six statues present in this room, the fifth of which does not carry a weapon. To proceed in the quest, the player must retrieve a grand axe from the armory in the keeps east wing. Then by typing 'arm statue 5', the axe will disappear upon arming the statue and all six will glow, summoning the key. At the same time the four death soldiers appear to challenge the players and also serving as a warning more difficult battles lay ahead in the quest. The only exit out of here is north back into the west hall. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A room with many statues");
set_long(@ext This is a very large room in comparison to the other rooms in the keep. The ceiling is very high, and the stone walls fashion the room into a hexagonal shape. Six eight foot statues are equidistantly placed from both each other and the walls also in that formation, with an ancient insignia engraved on the floor directly in the center. As each statue stares directly at the one across from it in the hexagon, you wonder if they serve a purpose.
    0   
    |   
    @
ext);
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You dont hear a sound.");
add_exit(ROOMS+"inside11", "north");
ob = new(ITEM+"clone_statue1.c");
ob->move(this_object());
ob = new(ITEM+"clone_statue2.c");
ob->move(this_object());
ob = new(ITEM+"clone_statue1.c");
ob->move(this_object());
ob = new(ITEM+"clone_statue1.c");
ob->move(this_object());
ob = new(ITEM+"clone_statue1.c");
ob->move(this_object());
ob = new(ITEM+"clone_statue1.c");
ob->move(this_object());
set_items(([
({ "keep" }) : "The keep from within appears to be extremely dark and haunted.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon. A relatively large insignia is engraved in its center.",
({ "walls" }) : "The walls, equidistant from each other in a hexagonal shape, are fashioned of rough black stone and are completely plain.",
({ "wall" }) : "This wall, one of six equidistant from one another in a hexagonal shape, is fashioned of rough black stone and is completely plain.",
({ "insignia" }) : "The large insignia inscribed in the center of the floor is the horrifying symbol of Owedquar. It appears to have been engraved recently.",
({ "statues" }) : "Six statues stand tall staring at each other and the insignia in the center of the room in a hexagonal shape, equal in distance from both each other and from the walls of the room.",
({ "ceiling" }) : "The ceiling is very high above your head, approximately fifteen feet removed from the floor. It is well crafted of black stone and is very smooth.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning the ceiling and floor is very smooth.",
({ "room" }) : "This is a very large room, with six statues equally distant from each other and the walls facing each other and the insignia in the center of the room. The only visible exit is to the north.",
({ "exit" }) : "The only visible exit from this room is to the north.",
({ "hexagon" }) : "The walls of the room and the six statues staring at each other, all perfectly placed to be equally apart, form this shape almost perfectly.",
({ "rooms" }) : "The other rooms in the keep in comparison to this room are significantly smaller.",
]));
add_pre_exit_function("north", "go_north");
}

int go_north() {
if(present("death soldier")) {
write("The death soldier crosses his swords and prevents you from escaping.");
return 0;
}
if(this_player()->query_ghost()) {
return 1;
}
else
return 1;
}
