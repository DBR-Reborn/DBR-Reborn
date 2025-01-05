#include <std.h>
#include "../keep.h"

/* This is the room directly north of the great hall, and is also the room with the only stairway leading to the keeps upper level. There are no monsters in this room, as somewhat of a calm before the storm, because the monsters on the upper level are by far the strongest in the keep. Climbing up the stairs leads there, and going south leads directly back to the keep's great hall. */

inherit ROOM;

int a;

void create() {
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A small stairway room");
set_long(@ext A straight set of stairs leading up greets you as you enter this room. Other than the stairs being in the rooms northern end, there is nothing else present except an empty torch bearing on each of the two side walls. To the south is a dark passage that appears to lead to a four way intersection.
       
        up   
    @
    |
    0
ext); 
set_smell("default", "The air smells very old and stale");
set_listen("default", "You hear odd sounds coming from upstairs.");
add_exit(ROOMS+"inside9", "up");
add_exit(ROOMS+"inside4", "south");
set_items(([
({ "stairs" }) : "The stairs ascend upwards in a straight formation.",
({ "northern end" }) : "A straight set of stairs leading up begins here.",
({ "bearing" }) : "This is an empty torch bearing bolted into the wall.",
({ "passage" }) : "The passage appears very dark and appears to lead south.",
({ "wall" }) : "The wall is fashioned of rough black stone. An empty torch bearing is bolted into it.",
({ "intersection" }) : "What seems to be a four way intersection is barely seen to the south.",
({ "walls" }) : "The walls are fashioned of rough black stone. An empty torch bearing is bolted into both of them.",
({ "side walls" }) : "The walls are fashioned of rough black stone. An empty torch bearing is bolted into both of them.",
({ "side wall" }) : "The wall is fashioned of rough black stone. An empty torch bearing is bolted into it.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough.",
]));
add_pre_exit_function("up", "go_up");
a = 0;
}

void init() {
object ob;
::init();
if(present("legend key", this_player()) && a<1) {
ob = new(MON+"energy_mass.c");
ob->move(this_object());
ob = new(MON+"energy_mass.c");
ob->move(this_object());
ob = new(MON+"necromancer.c");
ob->move(this_object());
write("%^BOLD%^%^WHITE%^A thick white mist materializes before you. Two pulsing balls of purple energy appear on the two sides of it and a grey robed wizard takes shape in the center.%^RESET%^");
a++;
}
if(present("necromancer")) {
write("Necromancer says in Common: %^MAGENTA%^I am impressed you have made it this far. But i cannot let you go any further.%^RESET%^");
}
return;
}

int go_up() {
if(present("necromancer")) {
write("Necromancer says in Common: %^MAGENTA%^You shall not pass. Owedquar's Shadow wishes for you to die.%^RESET%^"); 
return 0;
}
write("You ascend the staircase to reach the upper floor.");
return 1;
}
