#include <std.h>
#include "../keep.h"

/* This is an abandoned room which was formerly used for the rifting of demons before the keep was overtaken by Owedquar's forces. It is accessible only with the blood stained key found in a secret hole in the misty field outside. Present in this room are three vampric demon mobs, to provide challenge to players coming in the room searching it for treasure. There are also twelve corpses of mutliated demons lying on the ground, and one of the twelve contains a special item called the Pentagram Robe, which can only be found if the player is observant and searches. The only exit from the room is south, which leads back into the keep's western hall. */

inherit "/std/vault";

void init() {
::init();
add_action("get", "get");
add_action("move", "move");
}

int get(string str) {
if(str == "corpse" || str == "carcass") {
message("my_action", "You try to pick up the carcass but you are far too grossed out to do so.", this_player());
return 1;
}
}

int move(string str) {
if(str == "corpse" || str == "carcass") {
message("my_action", "You move the carcass an inch across the floor before you are to sickened to move it further.", this_player());
return 1;
}
}

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A blood splattered room");
set_long(@ext Never in your life have you seen a room more disgustingly stained in blood than here. The smooth black ceiling, floor, and rough walls of the room are completely plain and almost appear red due to the smeared blood, and numerous mutliated carcasses are lying about. The only obvious exit from this room is blocked by a red door in the rooms southern end.
  
    @
    |
    0
ext);
set_smell("default", "The air smells rotten and disgusting.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside6", "south");
set_door("red door", ROOMS+"inside6", "south", "blood key");
set_open("red door", 1);
set_locked("red door", 0);
set_lock_level("red door", 1000);
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
ob->set("aggressive", 1);
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
ob = new(ITEM+"demon_corpse1.c");
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
({ "exit" }) : "The exit from this room is located in the southern end and is home to a red door.",
({ "red door" }) : "This is a relatively bright red door, with a pentagram symbol above its center and a keyhole shaped like a horizontal line with a very small vertical line descending from its center is located on the middle right half.",
({ "door" }) : "This is a relatively bright red door, with a pentagram symbol above its center and a keyhole shaped like a horizontal line with a very small vertical line descending from its center is located on the middle right half.",
({ "walls" }) : "The walls are fashioned of rough black stone and while plain of art or protruding features are totally covered in old blood.",
({ "blood" }) : "This blood appears very old and is incontrovertibly disgusting. It is splattered and smeared everywhere.",
({ "southern end" }) : "A red door is positioned in this section of the room between the exit.",
({ "room" }) : "The room looks very sickening as it is filled with old blood.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning ther ceiling and floor is very smooth. All of the above are heavily stained with blood",
({ "ceiling" }) : "The ceiling is well crafted of black stone and is very smooth. It is splattered with dried blood",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon. It is almost completely covered in smeared old blood and is also the new home to numerous carcasses",
({ "corpses" }) : "There are a great deal of horribly mutilated corpses scattered all across the floor.",
({ "wall" }) : "The wall is fashioned of rough black stone and while plain of art or protruding features is totally covered in old blood.",
({ "carcass" }) : "This is a sickly mutilated corpse of what appears to have formerly been a demon when alive.",
]));
}
