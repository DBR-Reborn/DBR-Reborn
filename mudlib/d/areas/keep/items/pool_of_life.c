#include <std.h>

/* This is a pool filled with sacred holy water which is located in the Lidfino worship room of the black keep. It serves no purpose other than decoration to let players know the room they are in due to its importance, but the room itself does have a part in the areas quest and the pool being here is part of it. */

inherit OBJECT;

void init() {
::init();
add_action("drink", "drink");
}

int drink(string str) {
if(id(str)) {
message("my_action", "You attempt to drink water out of the pool, but a very strange force somehow works your conscience and you refrain from doing so.", this_player());
return 1;
}
}

void create() {
::create();
set_name("pool of life");
set("id", ({ "pool", "circular pool", "pool of water", "circular pool of water", "pool filled with water", "circular pool filled with water" }));
set_short("A circular pool filled with water");
set_long("This is a relatively large pool, fashioned of extremely rough bright white stone and appearing to be about two feet tall. It is filled almost to the top with extremely pure water which sits still without even making a ripple. A very large head bust of Lidfino, the God of Life, is molded onto the back of the pool, which lets all those who enter know the water contained in this pool is very sacred.");
set_weight(10000000);
set_value(0);
}
