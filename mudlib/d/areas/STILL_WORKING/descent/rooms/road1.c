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
    set("long", "You are now walking the main road of the Gnomish settlement. You don't see all too many people walking by, which makes you decide that this place probably isn't all that big.");
    add_exit(ROOMS+"road2", "west");
    add_exit(ROOMS+"gate1", "east");
        if(!present("gnome")){
  new(MON+"gnome_guard")->move(this_object());
  new(MON+"gnome_guard")->move(this_object());
}
}
