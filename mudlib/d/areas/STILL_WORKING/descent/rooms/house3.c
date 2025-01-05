//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set("short", "Inside the house of a Gnome Family.");
    set("long", "This is the house of some Gnomish citizen. It is quite small - only 3 rooms, and judging from the multitude of toys lying about, quite a large family inhabits this place. Still, it looks like a happy home, and you're glad to be here.");
    add_exit(ROOMS+"road6", "east");
        if(!present("gnome")){
  new(MON+"gnome")->move(this_object());
  new(MON+"gnome")->move(this_object());
  new(MON+"gnome")->move(this_object());
}
}
