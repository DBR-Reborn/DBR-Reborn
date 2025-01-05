#include <std.h>

/* This gem is one of the three gems required for the black keep quest. It is used to activate the green arcane orb on the keeps main level, and upon use it is destroyed. To get this gem, the player must get the contract from the assassins quarters by pulling it out with highly spelled strength, and take it to the dwarves living in mount nelfton. The only clue given for this location is in the library, where one of the books mentions dwarves live there. The player must also find the hidden black axe in the basement leading to the library as proof to show the dwarf of Merik's death, as explained in the contract. The green gem is given to the player when both these items are given to the dwarves. This gem is not located in the keep for the reason of forcing the player to use logic and piece together clues. */

inherit OBJECT;

void create() {
::create();
set_name("green gem");
set("id", ({ "gem", "green gem" }));
set_short("%^GREEN%^A green gem%^RESET%^");
set_long("This is a bright gem, colored perfectly green with no evidence of any different colors. A significant pattern of energy charges soar through your hand as you clutch it tightly.");
set_property("no save", 1);
set_weight(50);
set_value(250000);
}
