#include <std.h>
#include "../keep.h"
inherit "/std/obj/corpse.c";

/* This is the carcass of a slaughtered demon. It is present in the abandoned rifting room in the black keep. There are twelve carcasses in the room, and only one of them contains the special item called the Pentagram Robe. This is the one. */

void create() {
object ob;
::create();
set_name("a ferociously mutliated demon");
set("id", ({ "corpse", "demon corpse", "mutliated corpse" }));
set_short("A bloody demon carcass");
set_long("This is a clump of terrifyingly mutliated remains from what appears to have been from a demon. You see something somewhat shaped like a pentagram buried inside of it.");
set_weight(200);
set_value(0);
set_property("no decay", 1);
ob = new(ARMOUR+"pentagram_robe.c");
ob->move(this_object());
}
