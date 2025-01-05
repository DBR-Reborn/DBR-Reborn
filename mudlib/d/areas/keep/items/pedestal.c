#include <std.h>

/* This is the standard pedestal that is located in all three of the rooms containing colored arcane orbs. It has no purpose other than to add to realism and serve as decoration. When the orb is activated by the player and then shattered, the long description is changed accordingly upon the event. */

inherit OBJECT;

void create() {
::create();
set_name("pedestal");
set("id", ({ "pedestal", "gold pedestal", "golden pedestal" }));
set_short("%^YELLOW%^A golden pedestal%^RESET%^");
set_long("This is a generally cylindrical pedestal fashioned completely of solid gold. It stands approximately four feet tall and carries four prongs at its top protruding upward in a circle. Sitting on top of them is a shiny perfectly spherical orb."); 
set_weight(10000000);
set_value(0);
}
