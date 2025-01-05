//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 1);
    set_property("night light", 1);
    set_property("indoors", 1);
    set("short", "The Vermin Lair.");
    set("long", "The tunnel curves another way, this time to the south and east. It is extremely dark now, and you can only guess as to how the inhabitants navigate around here.");
    add_exit(ROOMS+"lair5", "south");
    add_exit(ROOMS+"lair7", "east");
        if(!present("rat"))
  new(MON+"giant_rat.c")->move(this_object());
}
