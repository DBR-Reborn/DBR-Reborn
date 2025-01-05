#include <std.h>

inherit OBJECT;

void init() {
    ::init();
    add_action("enter", "enter");
}

int enter(string str) {
    if(id(str)) {
	if(this_player()->query_class() != "assassin") {
	    message("my_action", "Only assassin ptesters may use this portal.", this_player());
	    return 0;
	}
	message("my action", "%^CYAN%^You enter the portal and are magically transported to the Assassin's Guild!%^RESET%^", this_player());
	this_player()->move_player("/d/damned/guilds/join_rooms/assassin_join");
	return 1;
    }
}

void create() {
    ::create();
    set_property("no get", 1);
    set_name("portal");
    set("id", ({ "portal", "shimmering portal" }));
    set_weight(10000000);
    set_value(0);
    set_short("%^BOLD%^%^MAGENTA%^A shimmering portal%^RESET%^");
    set_long("This portal is comprised of pure shimmering energy and seems to make an endless humming sound as you get closer to it. Perhaps you should 'enter' it and see what happens?");
    return;
}
