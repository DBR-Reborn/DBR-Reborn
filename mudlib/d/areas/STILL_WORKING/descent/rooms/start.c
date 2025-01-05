//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set("short", "Descent.");
    set("long", "You are in a massive cavern, with the ceiling a good 200 feet above you. You feel a little dizzy looking up, and turn your gaze around the room. A long coil of rope droops down from the ceiling near you, probably to climb up to get out of here. What appear to be roads lead southwest and west.");
set_items( (["rope" : "Climb it and go up to get out of here.",
"ceiling" : "Damn, is it high!" ]) );
    add_exit("/d/damned/virtual/room_43_2.world", "up");
    add_exit(ROOMS+"gate1", "southwest");
    add_exit(ROOMS+"path", "west");
}
