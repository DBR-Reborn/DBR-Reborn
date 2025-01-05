#include <std.h>

/* This is a crystal ball that is located in the warlock room of the black keep in the west wing. There are three present, and they are for decorative purposes only. However, they provide a vague quest clue when combined with the gem banner on the wall, the fact that the player needs the gems to activate the orbs. */

inherit OBJECT;

void init() {
::init();
add_action("get", "get");
}

int get(string str) {
if(id(str)) {
message("my_action", "The crystal ball is embedded in the platform, and will not budge.", this_player());
return 1;
}
}

void create() {
::create();
set_name("crystal ball");
set("id", ({ "ball", "crystal", "crystal ball" }));
set_short("A crystal ball");
set_long("This is a very large spherical ball fashioned entirely of crystal, positioned in a triangular formation with two other balls on a platform in the center of the room.");
set_weight(10000000);
set_value(0);
}
