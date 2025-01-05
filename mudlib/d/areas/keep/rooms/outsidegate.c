#include <std.h>
#include "../keep.h"

inherit "/std/vault";

void create() {
object ob;
::create();
set_property("light", 1);
set_property("indoors", 0);
set_short("The keep gates");
set_long(@ext You are now standing at the front of the large gate leading inside a huge black keep, Looking over the keep, you see absolutely no light coming from inside. To your rear, above a moat of polluted water, you see a draw bridge which leads away from the keep. Due to the extremely thick mist, it is difficult to see anything else beyond the bridge or moat. Lying on the two sides of the gate are two horribly battered corpses, likely those of the former keep guardians.
       
        gate   
    @
    |
    0
ext);
set_smell("default", "The air smells of death.");
set_listen("default", "You dont hear a sound.");
add_exit(ROOMS+"inside1", "gate");
add_exit(ROOMS+"outside1", "south");
set_door("gate", ROOMS+"inside1", "gate", "no key door");
set_open("gate", 0);
set_locked("gate", 0);
ob = new(ITEM+"battered_corpse.c");
ob->move(this_object());
ob = new(ITEM+"battered_corpse.c");
ob->move(this_object());
set_items(([
({ "dragon" }) : "The two large black dragons on the gate cover one half apiece as they stare at each other.",
({ "sides" }) : "The two sides of the gate leading into the keep are accompanied each by a battered corpse.",
({ "water" }) : "The water in the moat is horribly polluted. It appears light grey through the mist.",
({ "mist" }) : "The mist is incredibly thick, so much so that you can barely make out your own hands.",
({ "bridge" }) : "Rotting unsturdy wood appearing to be decades old comprises the draw bridge.",
({ "moat" }) : "The moat beneath the bridge surrounding the keep is filled with extremely old and polluted water, which gives off a grey hue.",
({ "keep" }) : "The keep close up is pitch black in color, without a single beam of light coming from it.",
({ "gate" }) : "The gate is about ten feet tall, and is engraved with two ferocious dragons facing each other.",
]));
add_pre_exit_function("south", "go_south");
add_pre_exit_function("north", "go_north");
}

int go_south() {
write("You cross the draw bridge, despite nearly falling into the moat from some of the rotting wood buckling beneath your feet.");
return 1;
}
