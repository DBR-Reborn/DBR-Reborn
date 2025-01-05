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
    set("long", "The tight and uncomfortable tunnel runs north and south. A little cave is to your west. You begin to notice droppings of some sort on the floor, and you have to move very carefully around them, not an easy feat when it is already so cramped.");
set_items( (["cave" : "Move west for a closer look.",
"droppings" : "They look like... rat droppings." ]) );
    add_exit(ROOMS+"cave", "west");
    add_exit(ROOMS+"lair3", "south");
    add_exit(ROOMS+"lair5", "north");
        if(!present("rat"))
  new(MON+"giant_rat.c")->move(this_object());
}
