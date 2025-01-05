#include <std.h>
#include "../keep.h"

/* This is the secret room which is uncovered by searching the rocks in the misty field room directly west of the black keep. Located in this hidden room is the blood stained key, one of the three keys required to open certain doors inside the keep. There are three large snakes in this room, to both provide some extra experience for those players that dont want to enter the keep and to provide challenge to mid level players who can handle the rear room of the misty fields. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", -2);
set_property("indoors", 1);
set_short("A small dark hole");
set_long(@ext You have fallen about fifteen feet down an extremely dark hole. The walls are earth as well as the floor, and you hear a good deal of sound, as if something is slithering throughout the pit. Looking above you, you can barely see the misty outside.
       
        up   
    @
ext);
set_smell("default", "It smells very rotten.");
set_listen("default", "You hear slithering noises.");
add_exit(ROOMS+"outside4", "up");
ob = new(MON+"snake.c");
ob->set_property("aggressive", 1);
ob->move(this_object());
ob = new(MON+"snake.c");
ob->set_property("aggressive", 1);
ob->move(this_object());
ob = new(MON+"snake.c");
ob->set_property("aggressive", 1);
ob->move(this_object());
ob = new(ITEM+"blood_key.c");
ob->move(this_object());
set_items(([
({ "outside" }) : "The outside is far above you, and filled with thick mist.",
({ "hole" }) : "The hole is extremely dark, and the only light coming in is from the mist above you.",
({ "pit" }) : "The pit is extremely dark, and the only light coming in is from the mist above you.",
({ "earth" }) : "The earth throughout the room is somewhat hard, but not impossible to punch through if one tried.",
({ "mist" }) : "The mist far above your position appears to be extremely thick.",
({ "wall" }) : "The walls are made of dirt and earth, and are completely natural.",
({ "walls" }) : "The walls are made of dirt and earth, and are completely natural.",
({ "floor" }) : "The floor is smooth natural earth which seems to have been frequently traveled upon.",
]));
add_pre_exit_function("up", "go_up");
}

int go_up() {
write("Punching your fingers into the rough earth, you slowly but eventually climb your way out of the hole.");
return 1;
}
