#include <std.h>
#include "../keep.h"

/* This room is the library of the black keep. It is the only room of the areas fifty that is sacred where no fighting can occur. Present in the room is the librarian mob, who serves several purposes in the quest. One is to give the player the holy soul globe if his summoning spellbook is returned to him. The other is the only clue to the segment of the quest dealing with the green gem, the fact the dwarves who built the keep live on Mount Nelfton. The librarian also tells the entire history of the keep when the player types 'talk to librarian' several times. The only exit from this room is north back into the basement hall. */

inherit ROOM;

void init() {
::init();
add_action("get", "get");
}

int get(string str) {
if(str == "chair") {
message("my_action", "Librarian says in Common: Hey you! That chair belongs where it is.", this_player());
return 1;
}
if(str == "table") {
message("my_action", "Librarian says in Common: That table belongs exactly where it is. Please do not move it.", this_player());
return 1;
}
if(str == "book") {
message("my_action", "Librarian says in Common: Please do not touch the books. They are only permitted to be read by those given permission by the master. However, i can tell you a summary of what is in them if you wish.", this_player());
return 1;
}
}

void create() {
object ob;
::create();
set_property("light", 2);
set_property("indoors", 1);
set_short("A well lit library");
set_long(@ext Two extremely bright lanterns hanging from the ceiling capture your attention as you enter this very large room, for most other rooms of this keep are far more dark. Two levels of bookcases seperated by a walkway with a ladder leading up to it from the floor rest against the walls, and every book present is very neatly stocked. The floor is noticeably smooth and covered with a well designed rug, and two tables and chairs are present for those who wish to make use of the materials in this room or to simply relax.
  
    @
    |
    0
ext); 
set_smell("default", "The air smells somewhat fresh.");
set_listen("default", "You hear faint footsteps and voices.");
add_exit(ROOMS+"inside16", "south");
ob = new(MON+"librarian.c");
ob->move(this_object());
/*
ob = new("/std/tailwind/obj/table.c");
ob->move(this_object());
ob = new("/std/tailwind/obj/table.c");
ob->move(this_object());
ob = new("/std/tailwind/obj/chair.c");
ob->move(this_object());
ob = new("/std/tailwind/obj/chair.c");
ob->move(this_object());
*/
set_items(([
({ "lantern" }) : "This significantly bright lantern hangs from the ceiling and efficiently illuminates the room.",
({ "lanterns" }) : "These significantly bright lantern hang from the ceiling and efficiently illuminate the room.",
({ "ceiling" }) : "The ceiling is very smooth, with two highly bright lanterns hanging down from it.",
({ "room" }) : "This is a large room, Two bright lanterns provide light, and numerous well stocked books in two levels of bookcases divided by a walkway with a ladder leading to it comprise the walls. The only exit from here is south.",
({ "exit" }) : "The exit from this well lit library is to the south.",
({ "keep" }) : "The keep appears dark in most rooms, but halfway elegant and bright in here.",
({ "bookcase" }) : "This bookcase rests against the wall and is two stories tall. It is divided halfway up by a walkway and is completely full with neatly stocked books.",
({ "bookcases" }) : "The bookcases rest against the walls and are two stories tall. They are divided halfway up by a walkway and are completely full with neatly stocked books.",
({ "books" }) : "The books in the bookcases are very neatly stocked, and completely fill them.",
({ "walkway" }) : "This thick wooden walkway divides the bookcases in half above ten feet above the floor. It is accessible only from a single ladder.",
({ "wood" }) : "The wood fashioning the walkway is extremely thick and smooth. The ladder wood is smooth as well but far less thick.",
({ "ladder" }) : "This wooden ladder extends from the floor to the walkway about ten feet up.",
({ "floor" }) : "The floor is very smooth and completely covered by a well designed rug.",
({ "rug" }) : "This rug covers the entire floor and has intricate designs depicting war.",
({ "designs" }) : "The designs present on the floor rug depict war.",
({ "wall" }) : "The wall is completely covered by a large bookcase completely filled with neatly stocked books.",
({ "walls" }) : "The walls are completely covered by large bookcases completely filled with neatly stocked books.",
({ "materials" }) : "The materials present in this room are limited to just the numerous books stocked in the bookcases.",
({ "tables" }) : "The two tables present in the room are both complemented with a chair and are very flat, perfect spots for reading.",
({ "chairs" }) : "The two chairs, each positioned at one of the two tables, provide a place for one to sit should they wish to use the tables for their business.",
({ "levels" }) : "The two levels in this room are distinguished by a thick wooden walkway dividing them through the middle of the room.",
]));
}
