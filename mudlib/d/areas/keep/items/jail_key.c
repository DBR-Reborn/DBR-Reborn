#include <std.h>

/* This key is the rusted old key that is required to unlock the cell leading to the keeps jail, where the blue gem is located. It is hidden in the room description behind the torn curtains of the room with the red arcane orb, the intention of which to force players to look at everything in the room, even if the room already contains a vital item pertaining to the quest. */

inherit OBJECT;

void create() {
::create();
set_name("old key");
set("id", ({ "key", "old key", "rusted key", "rusted old key", "old rusted key" }));
set_short("A rusted old key");
set_long("This small key appears to be extraordinarily old. It is covered completely in very thick rust and looks as if it hasnt been used in ages.");
set_weight(20);
set_value(1);
}
