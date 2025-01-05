//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set("short", "Inside the house of the Gnome Elder.");
    set("long", "This is the large house of the Gnome Elder. Every Gnomish settlement has an elder who is in charge of the place, and keeps it running smoothly. Judging from the prosperity around you, this village must have a good leader.");
    add_exit(ROOMS+"walkway", "south");
        if(!present("gnome")){
  new(MON+"gnome_elder")->move(this_object());
  new(MON+"gnome_guard")->move(this_object());
  new(MON+"gnome_guard")->move(this_object());
}
}
