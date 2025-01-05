#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 0);
set_property("indoors",1);
add_exit(ROOMS+"sewer15.c", "west");
set("short", "City Sewers");
set("day long", "You are in the sewers of a once great city. Slug drips off the walls. This is one of two housing rooms for the personal guards of the rat-lord. Rat-man lie around the room waiting for the day they can take a mortals head and drink from the skull.");
set("night long", "You are in the sewers of a once great city. Slug drips off the walls. This is one of two housing rooms for the personal guards of the rat-lord. Rat-man lie around the room waiting for the day they can take a mortals head and drink from the skull.");
set_smell("default", "The cold wind feels like death on your skin");
set_listen("default", "sounds of rats fill the sewer tunnels.");
}
void reset() {
 ::reset();
if(!present("rat"))
new(MON+"rat_adv_guard.c")->move(this_object());
new(MON+"rat_adv_guard.c")->move(this_object());
new(MON+"shadow_rat")->move(this_object());
new(MON+"shadow_rat")->move(this_object());
new(MON+"shadow_rat")->move(this_object());
new(MON+"shadow_rat")->move(this_object());
}
