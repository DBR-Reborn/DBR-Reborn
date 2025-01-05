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
    set("long", "The amount of droppings on the floor has visibly increased. This disturbs you. What is living in this tunnel? You press onward.");
set_items( (["droppings" : "Sick. You wish these pests would clean up after themselves."]) );
    add_exit(ROOMS+"lair6", "north");
    add_exit(ROOMS+"lair4", "south");
        if(!present("rat")){
  new(MON+"giant_rat.c")->move(this_object());
  new(MON+"giant_rat.c")->move(this_object());
}
}
