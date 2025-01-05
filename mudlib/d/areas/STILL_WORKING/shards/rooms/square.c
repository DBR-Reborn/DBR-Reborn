#include "../shards.h"
#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("pray", "pray");
}

void create() {
    ::create();
    set("short", "The Defiled Church");
    set("long",
      "This used to be some sort of place of worship. It has now been completely trashed. Ancient skeletons litter the floor, and the ceiling has partially collapsed. On the floor is a large hole, where a trap door was once set. The main exit is to your north, but to the west is a destroyed hospital.");
    set_exits( 
      ([ "north" : ROOMS+"ak_bless2",
      "down" : ROOMS+"post",
      "west": ROOMS+"hospital" ]));
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no attack", 1);
    set_property("no steal", 1);
    set_property("no castle", 1);
    set_property("no spell", 1);

    set_items( ([ "ceiling" : "The ceiling has probably just begun to collapse, within the past five years. A shame - you can tell it was a beautiful one at some point in the distant past.",
       "skeletons" : "The skeletons crumble whenever you touch them. It's a little too late to help these poor guys.",
      "hole" : "It leads into darkness. Be careful.",
      "floor" : "The floor is covered with dust, probably the by-product of no one being here in a few hundred years."
       ]) );
}

int pray() {
    if(!this_player()->query_ghost()) {
	notify_fail("You are already alive.\n");
	return 0;
    }
    write("Despite the long years of inactivity, this church is still guarded by Lidfino, and he bestows life upon you.\n", environment(this_player()));
    this_player()->revive();
    this_player()->set_hp(10);
    this_player()->set_heart_beat(1);
    return 1;
}
