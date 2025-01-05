#include <std.h>
#include "../keep.h"

/* This is a bloody room formerly owned by a powerful demon master in the black keep. There are six vampiric demons in this room, and it is the room with more set mobs than any other in the keep. This room was chosen for that challenge because the player needs the blood stained key to access it from the west wing, they cannot just walk in. This room has no visible exits other than going back north, but there is a hidden passage downstairs leading to the jail. To find it, the player must move the corpses several times, the number being random. When enough corpses have been moved, a button will be revealed on the floor. When the button is pushed part of the floor will descend into stairs. */

inherit "/std/vault";

object ob;
int a;
int b;
int c;

void init() {
::init();
add_action("push", "push");
add_action("get", "get");
add_action("move", "move");
}

int push(string str) {
if(str == "button" && present("button")) {
if(a==0) {
message("my_action", "You push the button and part of the floor transforms to create a stairway leading down.", this_player());
message("my_action", this_player()->query_cap_name() +" pushes the button on the floor, causing part of it to transform into a stairway leading down.", environment(this_player()));
add_exit(ROOMS+"inside35", "down");
set_door("red door", ROOMS+"inside19", "north", "blood key");
set_open("red door", 1);
set_locked("red door", 0);
set_lock_level("red door", 1000);
set_items(([
({ "stone" }) : "The stone comprising the walls of the room and the stairway leading down is black and extremely rough, while the stone fashioning the ceiling and floor is very smooth. All of the above are heavily stained with blood.",
({ "stairway" }) : "The railless stairway is fashioned of rough black blood soaked stone and leads down.",
({ "carcass" }) : "This is a sickly mutilated corpse of what appears to have formerly been a demon when alive.",
({ "wall" }) : "The wall is fashioned of rough black stone and while plain of art or protruding features is totally covered in old blood.",
({ "corpses" }) : "There are a great deal of horribly mutilated corpses scattered across the floor, most of which near the center of the room.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon. It is almost completely covered in smeared old blood and is also the new home to numerous carcasses",
({ "ceiling" }) : "The ceiling is well crafted of black stone and is very smooth. It is splattered with dried blood",
({ "room" }) : "The room looks very sickening as it is filled with old blood.",
({ "northern end" }) : "A red door is positioned in this section of the room between the exit.",
({ "blood" }) : "This blood appears very old and is incontrovertibly disgusting. It is splattered and smeared everywhere.",
({ "walls" }) : "The walls are fashioned of rough black stone and while plain of art or protruding features are totally covered in old blood.",
({ "door" }) : "This is a relatively bright red door, with a pentagram symbol above its center and a keyhole shaped like a horizontal line with a very small vertical line descending from its center is located on the middle right half.",
({ "red door" }) : "This is a relatively bright red door, with a pentagram symbol above its center and a keyhole shaped like a horizontal line with a very small vertical line descending from its center is located on the middle right half.",
({ "exit" }) : "The exit from this room is located in the northern end and is home to a red door.",
({ "carcasses" }) : "There are numerous ferociously mutilated carcasses of what appear to formerly have been demons lying on the floor.",
]));
a++;
return 1;
}
if(a==1) {
message("my_action", "The button has already been pushed.", this_player());
return 1;
}
}
}

int get(string str) {
if(str == "corpse" || str == "carcass" ) {
message("my_action", "You try to pick up the carcass but you are far too grossed out to do so.", this_player());
return 1;
}
}

int move(string str) {
if(str == "corpse" || str == "carcass" ) {
if(c<b || c>b) {
message("my_action", "You move the carcass an inch across the floor before you are too sickened to move it further.", this_player());
c++;
return 1;
}
if(c==b) {
message("my_action", "You move the carcass a little and you uncover a small stone button hidden underneath it!", this_player());
ob = new(ITEM+"button.c");
ob->move(this_object());
c++;
return 1;
}
}
}

void create() {
::create();
a = 0;
b = (random(9) + 3);
c = 0;
set_property("light", -1);
set_property("indoors", 1);
set_short("A blood splattered room");
set_long(@ext This room is absolutely horrid, almost completely covered in blood. A large number of horribly mutilated carcasses are spread out across the stained smooth floor, and the walls and ceiling look similar iminus the corpses, that being black but almost red in apperance due to the blood. Looking around you see the only noticeable exit from this disgusting place to the north through a red door.
    0   
    |   
    @
ext);
set_smell("default", "The air smells rotten and disgusting.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside19", "north");
ob = new(MON+"vampiric_demon.c");
ob->set("aggressive", 1);
ob->move(this_object());
ob = new(MON+"vampiric_demon.c");
ob->set("aggressive", 1);
ob->move(this_object());
ob = new(MON+"vampiric_demon.c");
ob->set("aggressive", 1);
ob->move(this_object());
ob = new(MON+"vampiric_demon.c");
ob->set("aggressive", 1);
ob->move(this_object());
ob = new(MON+"vampiric_demon.c");
ob->set("aggressive", 1);
ob->move(this_object());
ob = new(MON+"vampiric_demon.c");
ob->set("aggressive", 1);
ob->move(this_object());
ob = new(ITEM+"demon_corpse2.c");
ob->move(this_object());
ob = new(ITEM+"demon_corpse2.c");
ob->move(this_object());
ob = new(ITEM+"demon_corpse2.c");
ob->move(this_object());
ob = new(ITEM+"demon_corpse2.c");
ob->move(this_object());
ob = new(ITEM+"demon_corpse2.c");
ob->move(this_object());
ob = new(ITEM+"demon_corpse2.c");
ob->move(this_object());
ob = new(ITEM+"demon_corpse2.c");
ob->move(this_object());
ob = new(ITEM+"demon_corpse2.c");
ob->move(this_object());
ob = new(ITEM+"demon_corpse2.c");
ob->move(this_object());
ob = new(ITEM+"demon_corpse2.c");
ob->move(this_object());
ob = new(ITEM+"demon_corpse2.c");
ob->move(this_object());
ob = new(ITEM+"demon_corpse2.c");
ob->move(this_object());
set_items(([
({ "carcasses" }) : "There are numerous ferociously mutilated carcasses of what appear to formerly have been demons lying on the floor.",
({ "exit" }) : "The exit from this room is located in the northern end and is home to a red door.",
({ "red door" }) : "This is a relatively bright red door, with a pentagram symbol above its center and a keyhole shaped like a horizontal line with a very small vertical line descending from its center is located on the middle right half.",
({ "door" }) : "This is a relatively bright red door, with a pentagram symbol above its center and a keyhole shaped like a horizontal line with a very small vertical line descending from its center is located on the middle right half.",
({ "walls" }) : "The walls are fashioned of rough black stone and while plain of art or protruding features are totally covered in old blood.",
({ "blood" }) : "This blood appears very old and is incontrovertibly disgusting. It is splattered and smeared everywhere.",
({ "northern end" }) : "A red door is positioned in this section of the room between the exit.",
({ "room" }) : "The room looks very sickening as it is filled with old blood.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning ther ceiling and floor is very smooth. All of the above are heavily stained with blood",
({ "ceiling" }) : "The ceiling is well crafted of black stone and is very smooth. It is splattered with dried blood",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon. It is almost completely covered in smeared old blood and is also the new home to numerous carcasses",
({ "corpses" }) : "There are a great deal of horribly mutilated corpses scattered across the floor, most of which near the center of the room.",
({ "wall" }) : "The wall is fashioned of rough black stone and while plain of art or protruding features is totally covered in old blood.",
({ "carcass" }) : "This is a sickly mutilated corpse of what appears to have formerly been a demon when alive.",
]));
add_pre_exit_function("down", "go_down");
}

int go_down() {
write("You walk down the stone steps to the lower level.");
return 1;
}
