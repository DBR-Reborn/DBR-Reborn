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
    set("long", "This is a dead-end in the rock tunnel. You maneuver carefully so as to not hurt yourself on the sharp rocks sticking out of the walls. The tunnel goes west.");
set_items( (["rocks" : "You go in for a closer look, and poke yourself in the nose. Oops. You step back and hit your head against a tunnel wall. What a genius." ]) );
    add_exit(ROOMS+"lair2", "west");
        if(!present("rat")){
  new(MON+"giant_rat.c")->move(this_object());
  new(MON+"giant_rat.c")->move(this_object());}
}
