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
    set("long", "You are now walking the main road of the Gnomish settlement. The traffic is beginning to get a little heavier, and you can hear merchants to the south. A smaller road branches off to the west, to some other location.");
    add_exit(ROOMS+"road4", "south");
    add_exit(ROOMS+"walkway", "west");
    add_exit(ROOMS+"road2", "north");
        if(!present("gnome")){
  new(MON+"gnome")->move(this_object());
  new(MON+"gnome")->move(this_object());
}
}
