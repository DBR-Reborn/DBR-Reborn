//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set("short", "The Vermin Lair.");
    set("long", "This is a long, east-west tunnel, with a hole to the southeast. You are surrounded by rock all around you, giving you a claustrophobic feeling. In addition, it is quite dark.");
    add_exit(ROOMS+"lair3", "west");
    add_exit(ROOMS+"path", "southeast");
    add_exit(ROOMS+"lair1", "east");
        if(!present("rat"))
  new(MON+"giant_rat.c")->move(this_object());
}
