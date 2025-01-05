#include <std.h>

/* This is a statue of Taul that is present in the mace of the lord worship room of the black keep. It is present for decoration purposes and to signify to players what the room is should they choose not to look at the description in the room. The room itself plays a part in the later part of the areas quest, but this statue does not. */

inherit OBJECT;

void create() {
::create();
set_name("taul statue");
set("id", ({ "statue", "majestic statue", "statue of taul", "majestic statue of taul", "taul statue", "majestic taul statue" }));
set_short("A majestic statue of Taul");
set_long("This is an enormous statue of Taul, the God of War and diety worshipped by the Mace of the Lord. It stands nearly ten feet tall and is painted various colors to look almost as if it is real. It appears adorned in extremely shiny silver armour, and carries a huge mace in both hands.");
set_weight(10000000);
set_value(0);
}
