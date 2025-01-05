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
    set("long", "This is the nest of the vermin inhabiting this tunnel! You feel fear as you see tiny of baby rats skitter around the room. Little rats become giant rats, and you wish you could kill all of the things. The nest on the floor is made mostly of straw, but has some cloth, and other artificial components.");
set_items( (["rats" : "You feel horror just looking at them. But they're kinda cute anyways.",
"nest" : "It's all worthless junk, sorry." ]) );
    add_exit(ROOMS+"lair7", "west");
        if(!present("rat")) {
  new(MON+"queen_rat.c")->move(this_object());
  new(MON+"giant_rat.c")->move(this_object());
  new(MON+"giant_rat.c")->move(this_object());
}
}
