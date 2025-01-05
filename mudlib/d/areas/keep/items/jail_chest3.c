#include <std.h>
#include "../keep.h"

/* This is one of the three chests present in the black keep's jail room, which is located in the basement of the area. The chest cannot be carried out regardless of strength, and is locked without a key to open it. To open the chest, a thief is required to pick it, but not alone because he cannot interrupt his longterm due to the large amounts of monsters created by the energy mass mob present in the room. Inside this chest is the blue gem, which is required to activate the blue arcane orb in the first floors east wing and is a vital part of the areas quest. */

inherit "/std/bag_logic";

void create() {
object ob;
::create();
set_name("chest");
set("id", ({ "chest", "well built chest", "built chest" }));
set_short("A well built chest");
set_long("This is a very well built wooden chest, heavily chained to the ground and locked tightly.");
set_weight(10000000);
set_value(0);
set_max_internal_encumbrance(1500);
set_possible_to_close(1);
toggle_closed();
set_lock("locked");
set_lock_level(25);
ob = new(ITEM+"blue_gem.c");
ob->move(this_object());
}
