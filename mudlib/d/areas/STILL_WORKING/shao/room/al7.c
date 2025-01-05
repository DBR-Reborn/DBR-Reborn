#include <std.h>
#include <shao.h>

inherit ROOM;
void init(){
    ::init();
    add_action("kick_wall", "kick");
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("night light", 0);
    set("short", "alley");
    set("long", "%^BOLD%^Garbage and old crates clutter "
"the narrow alley, and make passage difficult.\n"
"The alley continues north, south and east into darkness.  "
"A stone wall towers over you to the west...\n");
add_exit("al8", "north");
add_exit("al9", "east");
add_exit("al6", "south");

    set_smell("default", "The smell of piss and garbage is overwhelming.\n");
}
