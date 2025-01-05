#include <std.h>

/* This is designed to be the corpse of a former Knight of the Keep. It serves two purposes, one of which is to give the player somewhat of a cruel greeting before he opens the gate and enters the keep, the other somewhat as a reference to the former location of clan knights and that the clan is long gone. The corpse has no special use to the player */

inherit OBJECT;

void create() {
::create();
set_name("battered corpse");
set("id", ({ "corpse", "battered corpse" }));
set_short("A battered corpse");
set_long("This is a battered corpse of what appears to have formerly been a well built human.");
set_weight(100);
set_value(0);
}
