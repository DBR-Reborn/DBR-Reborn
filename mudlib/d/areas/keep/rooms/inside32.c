#include <std.h>
#include "../keep.h"

/* This is the hidden room of the black keep containing the red arcane orb, a vital room for the areas quest. To reach this room, the player must percieve the faint clue in the previous room about a draft and pass through the false wall to the west. There are no monsters in this room initially, but a powerful Silver Dragon appears once the player activates and shatters the orb to provide high challenge due to its powerful area breath attack. To activate the orb, the player must have the red gem in their inventory and 'touch' it. If they try to touch it without the gem or attempt to take it, they will get blasted and lose 500-1000 hp. A second quest item is also located in here, the old key required to open the jail cell. To find it, the player must open the curtain. The only exit from this room is east. */

inherit ROOM;

object ob;
int a;
int b;
int c;

void init() {
::init();
add_action("open", "open");
add_action("close", "close");
}

int open(string str) {
if(str == "curtain" && a<1) {
if(c<1) {
message("my_action", "You open the closed curtain and uncover a small rusted key!", this_player());
message("my_action", this_player()->query_cap_name() +" opens the curtain and uncoveres a small rusted key!", environment(this_player()));
ob = new(ITEM+"jail_key.c");
ob->move(this_object());
c++;
a++;
return 1;
}
if(c>0) {
message("my_action", "You open the curtain.", this_player());
message("my_action", this_player()->query_cap_name() +" opens the curtain.", environment(this_player()));
a++;
return 1;
}
set_items(([
({ "curtain" }) : "This open curtain covers a good deal of the wall in conjunction with other identical curtains and is dark purple in color.",
({ "curtains" }) : "The open curtains in this room cover a good deal of the wall and are dark purple in color.",
({ "chamber" }) : "This is a circular room, containing open curtains covering many parts of the walls and a golden pedestal standing four feet tall in the center. To the east is the only visible exit.",
({ "room" }) : "This is a circular room, containing open curtains covering many parts of the walls and a golden pedestal standing four feet tall in the center. To the east is the only visible exit.",
({ "exit" }) : "The exit from this circular chamber-esque room is to the east.",
({ "center" }) : "The center of this circular room contains a pure gold pedestal rising about four feet up from the floor.",
({ "walls" }) : "The walls are circular in shape and are almost completely covered in purple curtains. From what can be seen through small cracks is rough black stone.",
({ "wall" }) : "The wall is circular in shape and is almost completely covered in purple curtains. From what can be seen through small cracks is rough black stone.",
({ "floor" }) : "The floor of this room is extremely rough, built of thick black stone.",
({ "stone" }) : "The stone fashioning both the walls visible through curtain cracks and the floor is black and extremely rough, while the stone comprising the ceiling is very smooth.",
({ "ceiling" }) : "The ceiling is well crafted of black stone and is very smooth.",
({ "crack" }) : "This small crack in the curtains exposes part of the plain black stone walls of the room.",
({ "cracks" }) : "The cracks in the curtains expose part of the plain black stone walls of the room.",
({ "diameter" }) : "The diameter of this room is approximately twenty feet, a medium to large size.",
({ "keep" }) : "The keep from within appears very dark and haunted.",
]));
b = 0;
return 1;
}
if(str == "curtain" && a>0) {
message("my_action", "The curtain is already open.", this_player());
b = 0;
return 1;
}
message("my_action", "What?", this_player());
return 1;
}

int close(string str) {
if(str == "curtain" && b<1) {
message("my_action", "You close the curtain.", this_player());
message("my_action", this_player()->query_cap_name() +" closes the curtain.", environment(this_player()));
set_items(([
({ "chamber" }) : "This is a circular room, containing closed curtains covering almost every part of the walls and a golden pedestal standing four feet tall in the center. To the east is the only visible exit.",
({ "rooms" }) : "This is a circular room, containing closed curtains covering almost every part of the walls and a golden pedestal standing four feet tall in the center. To the east is the only visible exit.",
({ "curtains" }) : "The peculiarly closed curtains in this room cover almost the entire wall and are dark purple in color.",
({ "curtain" }) : "This peculiarly closed curtain covers almost the entire wall in conjunction with other identical curtains and is dark purple in color.",
({ "keep" }) : "The keep from within appears very dark and haunted.",
({ "diameter" }) : "The diameter of this room is approximately twenty feet, a medium to large size.",
({ "cracks" }) : "The cracks in the curtains expose part of the plain black stone walls of the room.",
({ "crack" }) : "This small crack in the curtains exposes part of the plain black stone walls of the room.",
({ "ceiling" }) : "The ceiling is well crafted of black stone and is very smooth.",
({ "stone" }) : "The stone fashioning both the walls visible through curtain cracks and the floor is black and extremely rough, while the stone comprising the ceiling is very smooth.",
({ "floor" }) : "The floor of this room is extremely rough, built of thick black stone.",
({ "wall" }) : "The wall is circular in shape and is almost completely covered in purple curtains. From what can be seen through small cracks is rough black stone.",
({ "walls" }) : "The walls are circular in shape and are almost completely covered in purple curtains. From what can be seen through small cracks is rough black stone.",
({ "center" }) : "The center of this circular room contains a pure gold pedestal rising about four feet up from the floor.",
({ "exit" }) : "The exit from this circular chamber-esque room is to the east.",
]));
b++;
a = 0;
return 1;
}
if(str == "curtain" && b>0) {
message("my_action", "The curtain is already closed.", this_player());
return 1;
}
message("my_action", "What?", this_player());
return 1;
}

void create() {
::create();
a = 0;
b = 0;
c = 0;
set_property("light", -1);
set_property("indoors", 1);
set_short("A dark circular room");
set_long(@ext This is a completely circular room, the walls covered with closed purple curtains suggesting that it is a chamber of magic. The smooth ceiling of the room is relatively low, only about six or seven feet high, and the room itself has a relatively spacious diameter of about twenty feet. The floor unlike most others in the keep is extremely rough matching the very small walls visible through cracks in the curtains, and in its center sits a cylindrical pedestal fashioned completely of solid gold.
  
    @--0
ext);
set_smell("default", "The air smells somewhat fresh.");
set_listen("default", "You hear mild noises of humming energy.");
add_exit(ROOMS+"inside24", "east");
ob = new(ITEM+"pedestal.c");
ob->move(this_object());
ob = new(ITEM+"red_orb.c");
ob->move(this_object());
set_items(([
({ "curtain" }) : "This peculiarly closed curtain covers almost the entire wall in conjunction with other identical curtains and is dark purple in color.",
({ "curtains" }) : "The peculiarly closed curtains in this room cover almost the entire wall and are dark purple in color.",
({ "room" }) : "This is a circular room, containing closed curtains covering almost every part of the walls and a golden pedestal standing four feet tall in the center. To the east is the only visible exit.",
({ "exit" }) : "The exit from this circular chamber-esque room is to the east.",
({ "center" }) : "The center of this circular room contains a pure gold pedestal rising about four feet up from the floor.",
({ "walls" }) : "The walls are circular in shape and are almost completely covered in purple curtains. From what can be seen through small cracks is rough black stone.",
({ "wall" }) : "The wall is circular in shape and is almost completely covered in purple curtains. From what can be seen through small cracks is rough black stone.",
({ "floor" }) : "The floor of this room is extremely rough, built of thick black stone.",
({ "stone" }) : "The stone fashioning both the walls visible through curtain cracks and the floor is black and extremely rough, while the stone comprising the ceiling is very smooth.",
({ "ceiling" }) : "The ceiling is well crafted of black stone and is very smooth.",
({ "crack" }) : "This small crack in the curtains exposes part of the plain black stone walls of the room.",
({ "cracks" }) : "The cracks in the curtains expose part of the plain black stone walls of the room.",
({ "chamber" }) : "This is a circular room, containing closed curtains covering almost every part of the walls and a golden pedestal standing four feet tall in the center. To the east is the only visible exit.",
({ "diameter" }) : "The diameter of this room is approximately twenty feet, a medium to large size.",
({ "keep" }) : "The keep from within appears very dark and haunted.",
]));
add_pre_exit_function("east", "go_east");
}

int go_east() {
if(present("silver dragon")) {
write("The Silver Dragon spreads its huge wings and roars at you as it blocks your exit.");
return 0;
}
else
return 1;
}
