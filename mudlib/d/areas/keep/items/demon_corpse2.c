#include <std.h>
#include "../keep.h"
inherit "/std/obj/corpse.c";

/* This is the carcass of a slaughtered demon. It is present in the two abandoned rifting rooms of the black keep. There are twelve carcasses in each of the two rooms, and in the northern room one of them contains the special item call the Pentagram Robe. This corpse is all the corpses in the southern room and one of the eleven without the robe in the northern room. This corpse in the southern room can be moved multiple times by the player and eventually a hidden button will be uncovered, which will reveal a stairway to the basement. */

void create() {
::create();
set_name("a ferociously mutliated demon");
set("id", ({ "corpse", "demon corpse", "mutliated corpse" }));
set_short("A bloody demon carcass");
set_long("This is a clump of terrifyingly mutliated remains from what appears to have been from a demon.");
set_weight(200);
set_value(0);
set_property("no decay", 1);
}
