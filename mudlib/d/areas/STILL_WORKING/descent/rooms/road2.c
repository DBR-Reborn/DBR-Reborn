//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set("short", "On the road of the Gnomish Settlement.");
    set("long", "You are now walking the main road of the Gnomish settlement. It's nice and peaceful here, which is nice. You've fought your way through so many other locales that it's nice to not be attacked for once.");
    add_exit(ROOMS+"road3", "south");
    add_exit(ROOMS+"road1", "east");
        if(!present("gnome")){
  new(MON+"gnome_guard")->move(this_object());
  new(MON+"gnome_guard")->move(this_object());
}
}
