
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 3);
set_property("night light",1);
add_exit(ROOMS+"sewer1.c", "north");
add_exit(WORLD+".world", "south");
set("short", "City Sewers");
set("night long", "You are in the sewers of a once great city. Slug drips off the walls. A stream running through the room bring water out of the city. There seems to be away out of the sewers to the south.");
set("day long", "You are in the sewers of a once great city. Slug drips off the walls. A stream running through the room bring water out of the city. There seems to be away out of the sewers to the south.");
set_smell("default", "The cold wind feels like death on your skin");
set_listen("default", "sounds of rats fill the sewer tunnels.");
new(ITEM+"sewer_stream.c")->move(this_object());
set_pre_exit_functions( ({"north"}), ({"go_north"}) );
}
void reset() {
 ::reset();
if(!present("rat"))
new(MON+"rat_guard.c")->move(this_object());
}

int go_north() {
   if(present("rat")) {
      if(this_player()->query_invis()) return 1;
      if(this_player()->query_stealth() >= 40) return 1;
      if(this_player()->query_hiding() >= 30) return 1;
      if(this_player()->query_ghost()) return 1;
      write("The rat-man pushes you back and shakes his head.");
      tell_room(this_object(), this_player()->query_cap_name() +
           " tried to go north, but was pushed back by the rat-man.",
           ({ this_player() }) );
      return 0;
      }
   else
      return 1;
}

