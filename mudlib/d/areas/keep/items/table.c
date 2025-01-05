#include <std.h>

/* This is the table in the arch mage room of the black keep that the many books pertaining to arch mage magic sit stacked upon. It cannot be carried due to its anchoring, and serves no special purpose. */

inherit OBJECT;

void create() {
::create();
set_name("table");
set("id", ({ "table", "wooden table" }));
set_short("A wooden table");
set_long("This well anchored wooden table serves as a flat surface for either stacking things on top of or as a place to read books or write.");
set_weight(1000000);
set_value(0);
}
