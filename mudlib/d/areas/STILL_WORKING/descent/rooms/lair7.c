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
    set("long", "Without warning, the tunnel suddenly begins to widen and expand, and you can tell you're near some sort of feeding grounds. Bones lie all around on the floor, partially gnawed by some sort of critter with _big_ teeth. The tunnel is even bigger to the east.");
set_items( (["bones" : "They must have had some tasty meat on them at one point. Hmm, that one looks human... your stomach sickens."]) );
    add_exit(ROOMS+"lair6", "west");
    add_exit(ROOMS+"lair8", "east");
        if(!present("rat")) {
  new(MON+"giant_rat.c")->move(this_object());
  new(MON+"giant_rat.c")->move(this_object());
}
}
