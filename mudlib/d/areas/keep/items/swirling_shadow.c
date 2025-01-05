#include <std.h>

/* This swirling shadow serves the purpose of being the portal used to access the Dark Paladin Guild in the black keep. The shadow is located 3n2w1n of the keep entrance, and to enter it the player types 'enter shadow'. Only dark paladins and newbies with no guild will be transported to the guild. If someone of a different guild attempts to enter the portal, they will be transported to the underworld. */

inherit OBJECT;

void init() {
::init();
add_action("enter", "enter");
}

int enter(string str) {
if(id(str)) {
message("my_action", "%^BOLD%^%^MAGENTA%^You step directly into the swirling shadow. Almost immediately upon doing so you are transported directly beneath the floor to the start of a thin hallway.%^RESET%^", this_player());
this_player()->move_player("/d/damned/guilds/dark-paladin/entrance_room.c");
return 1;
}
}

void create() {
::create();
set_property("no get", 1);
set_name("shadow");
set("id", ({ "shadow", "swirling shadow" }));
set_weight(10000000);
set_value(0);
set_short("%^BOLD%^%^WHITE%^A swirling shadow%^RESET%^");
set_long("This pitch black shadow endlessly swirls, almost mesmorizing you. It appears to be some sort of a gateway that can lead to anywhere, possibly even beyond this realm. Perhaps one should 'enter' it and find out.");
}
