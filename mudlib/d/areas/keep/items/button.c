#include <std.h>
#include "../keep.h"

/* This is the button that is uncovered when the corpses in the southern abandoned demon rifting room are moved. When the player 'pushes' the button, a secret stairway is created leading downstairs in the room. */

inherit OBJECT;

void init() {
::init();
add_action("get", "get");
}

int get(string str) {
if(id(str)) {
message("my_action", "You cannot take the button, for it is part of the floor itself.", this_player());
return 1;
}
}

void create() {
::create();
set_name("button");
set("id", ({ "button", "stone button" }));
set_short("A stone button");
set_long("This is a square shaped button sticking up out of the blood soaked floor.");
set_weight(10000000);
set_value(0);
}
