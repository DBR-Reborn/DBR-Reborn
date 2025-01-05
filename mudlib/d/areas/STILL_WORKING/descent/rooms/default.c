//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set("short", "Short Desc.");
    set("long", "Long Desc.");
    add_exit(ROOMS+"exit1", "west");
    add_exit(ROOMS+"exit4", "south");
    add_exit(ROOMS+"exit6", "east");
    add_exit(ROOMS+"exit8", "north");
}
