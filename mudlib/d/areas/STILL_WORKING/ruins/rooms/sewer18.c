#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 0);
set_property("indoors", 1);
add_exit(ROOMS+"sewer15.c", "south");
set("short", "City Sewers");
set("day long", "You are in the sewers of a once great city. Slug drips off the walls. This is the house of the rat-lord. A very evil presents flows though the room.");
set("night long", "You are in the sewers of a once great city. Slug drips off the walls. This is the house of the rat-lord. A very evil presents flows though the room.");
set_smell("default", "The cold wind feels like death on your skin");
set_listen("default", "sounds of rats fill the sewer tunnels.");
 new(MON+"rat-lord.c")->move(this_object());
}
void reset() {
 ::reset();
if(!present("rat")){
new(MON+"rat_adv_guard.c")->move(this_object());
new(MON+"rat_adv_guard.c")->move(this_object());
  if(!present("rat-lord")){
    if(random(10)<1){
    new(MON+"rat-lord.c")->move(this_object());
    }
  }
}
}
