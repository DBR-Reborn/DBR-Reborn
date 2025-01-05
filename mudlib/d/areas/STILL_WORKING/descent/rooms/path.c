//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set("short", "The path.");
    set("long", "You are on the long path to the Gnomish mines. Many wheel barrow tracks line the road, probably from miners lugging back their hard-earned ingots. But where is everyone now? The path is completely unoccupied, when you can see there should be many people on it.");
set_items( (["path" : "It is pretty sturdy and well-packed.",
"tracks" : "Deep tracks - someone must have been moving something heavy." ]) );
    add_exit(ROOMS+"mine-enter", "west");
    add_exit(ROOMS+"start", "east");
    add_exit(ROOMS+"lair2", "northwest");
}
