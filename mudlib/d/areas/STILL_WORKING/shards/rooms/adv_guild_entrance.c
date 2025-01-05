//    Advanturer's Guild where everyone can train.
#include "../shards.h"
inherit "/std/room";

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The Wanderer of Life");
    set("long",
      "Unlike some other parts of this town, this building has held up very well against the years. Gaudy paintings still adorn the walls, and a few chairs and tables appear to be unbroken. You see a room to the south.");
    /*
      set_items(([ "sign" : (: call_other, this_object(), "read_sign" :) ]));
    */
    set_items(([ "paintings" : "Some of these must be worth a fortune! You try to tug one off the wall, but discover they are magically held there. Guess that explains their longetivity.",
"tables" : "Judging from their length and width, they were probably used for writing and studying.",
"chairs" : "You ponder sitting on one, but know that would just break it." ]));
    add_exit(ROOMS+"adv_guild_sk", "south");
    add_exit(ROOMS+"ak_tavern3", "east");
    return;
}

