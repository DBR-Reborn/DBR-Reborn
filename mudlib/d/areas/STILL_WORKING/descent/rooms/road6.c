//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set("short", "On the road of the Gnomish Settlement - Residential District.");
    set("long", "On the road of the Gnomish Settlement - Residential District.");
    set("long", "This area is much quieter than the markets to the north, because Gnomish women have been known to bean loud noise makers for annoying them. You consider this for a moment, and walk softly. The road stretches onward to the south, but there's nothing important there.");
    add_exit(ROOMS+"house3", "west");
    add_exit(ROOMS+"house4", "east");
    add_exit(ROOMS+"road5", "north");
        if(!present("gnome")){
  new(MON+"gnome")->move(this_object());
  new(MON+"gnome")->move(this_object());
}
}
