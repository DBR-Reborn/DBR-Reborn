#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 0);
set_property("indoors", 1);
add_exit(ROOMS+"sewer15.c", "southeast");
set("short", "City Sewers");
set("long", "You are in the sewers of a once great city. Slug drips off the walls. This room is a vast liberary. There is a Rat-man mage studying here. Books lie the slim covered walls");
set_smell("default", "The cold wind feels like death on your skin");
set_listen("default", "sounds of rats fill the sewer tunnels.");
set_pre_exit_functions( ({"southeast"}), ({"go_southeast"}));
}
void reset() {
 ::reset();
if(!present("rat"))
new(MON+"rat_mage")->move(this_object());
}
int go_southeast() {
   if(present("rat")) {
      if(this_player()->query_invis()) return 1;
      if(this_player()->query_ghost()) return 1;
      if(this_player()->query_hiding() >= 30) return 1;
      if(this_player()->query_stealth() >= 40) return 1;
      write("The rat-man pushes you back and shakes his head.");
      tell_room(this_object(), this_player()->query_cap_name() +
           " tried to go southeast, but was pushed back by the rat-man.",
          ({ this_player() }) );
      return 0;
      }
   else
      return 1;
}

