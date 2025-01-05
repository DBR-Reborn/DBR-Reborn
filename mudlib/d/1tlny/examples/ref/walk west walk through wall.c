#include <std.h>
#include "../keep.h"

/* This is a completely bare and abandoned room, no items are present in here. There are three shadow knights and a warlock in here to give players a feel for fighting multiple shadow knights and to offer challenge with the extra vampiric demons created by the warlock added during the battle. There is a hidden exit west given by a vague clue in the room description that leads to the red arcane orb, and a visible exit south back into the main intersection of the second floor. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", 0);
set_property("indoors", 1);
set_short("A bare abandoned room");
set_long(@ext This room is completely devoid of any material non-living objects. The air feels slightly cool as if a draft is coming in, despite the fact there are no windows, and a small amount of light from the south is providing minimal illumination. The well built stone walls, ceiling, and floor are completely plain and undamaged, almost as if the room was either never used or thoroughly abandoned.
   
    @
    |
    0
ext);
set_smell("default", "The air smells somewhat fresh.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside17", "south");
add_exit(ROOMS+"inside32", "west");
set_invis_exits(({ "west" }));
ob = new(MON+"shadow_knight.c");
ob->set("aggressive", 1);
ob->move(this_object());
ob = new(MON+"shadow_knight.c");
ob->set("aggressive", 1);
ob->move(this_object());
ob = new(MON+"shadow_knight.c");
ob->set("aggressive", 1);
ob->move(this_object());
ob = new(MON+"warlock.c");
ob->set("aggressive", 1);
ob->move(this_object());
set_items(([
({ "illumination" }) : "The illumination provided to this room is average at best. It is coming from the southern room.",
({ "southern room" }) : "From this room enough light is being transmitted to provide this one with mediocre illumination.",
({ "room" }) : "This is a completely empty room, with the walls, ceiling, and floor completely plain. The only visible exit is to the south.",
({ "light" }) : "The light illuminating this room is average at best. It is coming from the southern room.",
({ "walls" }) : "The walls are fashioned of rough black stone and are completely plain.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon.",
({ "ceiling" }) : "The ceiling is well crafted of black stone and is very smooth.",
({ "exit" }) : "The only visible exit from this room is in the south, leading into a somewhat lit area.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning the ceiling and floor is very smooth.",
({ "wall" }) : "The wall is fashioned of rough black stone and is completely plain.",
]));
add_pre_exit_function("west", "go_west");
}

int go_west() {
write("You begin to walk west and instead of bumping into the stone wall you pass directly through it!");
return 1;
}
