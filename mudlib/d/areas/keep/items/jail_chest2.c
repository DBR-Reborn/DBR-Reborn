#include <std.h>
#include "../keep.h"

/* This chest is one of the three chests that sit in the black keep's jail room, located in the basement level. It cannot be carried away, and is tightly locked with no available key to open it. Instead, a thief must do the honors. However, while doing so the thief will be under fire from constant assaults from random mobs created by the energy mass floating in the room. Inside this chest is various different types of money. This is to possibly throw players off as to what the other chests might contain, and to make it so each of the three chests have different content inside them. */

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
ob = new("/std/obj/coins");
ob->set_money("mithril", 2000);
ob->set_money("gold", 5000);
ob->set_money("silver", 5000);
ob->set_money("copper", 10000);
ob->move(this_object());
}
