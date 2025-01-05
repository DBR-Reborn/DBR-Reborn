//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "Inside the Gnome Mines.");
    set("long", "It is utterly dark here, which is strange, considering that the light from the shaft entrance should still be reaching you. A feeling of evil begins to creep upon you, and you can only guess at what lurks ahead.");
    add_exit(ROOMS+"mine5", "south");
    add_exit(ROOMS+"mine7", "north");
        if(!present("demon")) {
  new(MON+"demon.c")->move(this_object());
  new(MON+"demon.c")->move(this_object());
}
}
