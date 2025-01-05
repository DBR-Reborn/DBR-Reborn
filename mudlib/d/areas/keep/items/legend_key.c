#include <std.h>

/* This is the key that is required to unlock the crystal door on the second floor of the black keep. Recieving this item is the culmination of every single event of the areas quest before going after the final boss, Owedquar's Shadow. To get the key, a merchant with a 'blacksmith' skill of at least 400 must mold the three blessed crystal shards together at the Shadowforge in the center of the keep. The shards are recieved from activating the three arcane orbs with the gems of the respective colors, and are blessed by the three divine gods at various places in the keep when offered by members of the required guilds. */

inherit OBJECT;

void create() {
::create();
set_name("legend key");
set("id", ({ "key", "legend key" }));
set_short("%^BOLD%^%^YELLOW%^The Legend Key%^RESET%^");
set_long("This is a key fashioned entirely of pure crystal. It has three minature insignia of the divine gods in a triangular ring at its top, and at its bottom it contains prongs in an truly foreign formation. As you clutch this legendary object it flashes brilliantly in your hand, filling you with will.");
set_property("no save", 1);
set_weight(25);
set_value(1000000);
}
