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
    set("long", "Here, the tunnel turns north and west. It is getting increasingly harder to fit through. The air is starting to become even more stale than before, which makes you quite nervous...");
    add_exit(ROOMS+"lair4", "north");
    add_exit(ROOMS+"lair2", "east");
        if(!present("rat")){
  new(MON+"giant_rat.c")->move(this_object());
  new(MON+"giant_rat.c")->move(this_object());}
}
