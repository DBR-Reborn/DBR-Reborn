#include <std.h>
#include "../keep.h"

/* This is one of the three crystal shards that is needed in order to forge the legend key. The legend key is then later used to access the black keep's master room for the player to face off against Owedquar's Shadow. To get this shard, the player must activate the blue arcane orb with the blue gem found in the jail room in the east wing of the first floor and defeat the two Silver Dragons which appear to defend it. The shard however is not blessed when recieved. To bless it, it must be offered to Lidfino by a disciple at the pool of life. Upon doing so, the player will recieve life_shard2.c in their inventory. */

inherit OBJECT;

object ob;

void init() {
::init();
add_action("offer", "offer");
}

int offer(string str) {
if(id(str)) {
if(present("pool of life", environment(this_player())) && this_player()->query_class() == "disciple") {
message("my_action", "You place the crystal shard in the pool and offer it to Lidfino. The water in the pool begins to glow bright white, as do the eyes on the stone face overlooking it. A powerful voice is then heard.", this_player());
message("my_action", this_player()->query_cap_name() +" offers the crystal shard to Lidfino.", environment(this_player()));
tell_room(environment(this_player()), "A powerful voice speaks in Common: %^BLUE%^At long last, the chosen ones destined to send Owedquar to Hades have arrived. I have been watching you since your birth, observing your existence and witnessing truly amazing feats driven by unspeakable will. I, Lidfino, the God of Life, shall give you my blessing if you promise to destroy the ruler of evil.%^RESET%^");
tell_room(environment(this_player()), "");
tell_room(environment(this_player()), "%^BOLD%^%^WHITE%^Gleaming beams of energy are released from the eyes of the stone face into the water of the pool, enchanting the Crystal Shard of Life floating within it!%^RESET%^");
ob = new(ITEM+"life_shard2.c");
ob->move(ROOMS+"inside26.c");
remove();
return 1;
}
if(!present("pool of life", environment(this_player()))) {
message("my_action", "What?", this_player());
return 1;
}
message("my_action", "You place the crystal shard in the pool as an offering to the God of Life, but nothing seems to be happening as it floats.", this_player());
ob = new(ITEM+"life_shard1.c");
ob->move(ROOMS+"inside26.c");
remove();
return 1;
}
}

void create() {
::create();
set_name("life shard");
set("id", ({ "shard", "crystal", "crystal shard", "shard of life", "crystal shard of life", "life shard" }));
set_short("%^BOLD%^%^WHITE%^Crystal Shard of Life%^RESET%^");
set_long("This shard is a relatively small piece of pure one hundred percent delicate crystal. It is completely clear, and an extremely faint blue glow emanates from the inside.");
set_property("no save", 1);
set_weight(50);
set_value(500000);
}
