#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 0);
set_property("indoors", 1);
add_exit(ROOMS+"sewer18.c", "north");
add_exit(ROOMS+"sewer16.c", "west");
add_exit(ROOMS+"sewer17.c", "east");
add_exit(ROOMS+"sewer19.c", "northeast");
add_exit(ROOMS+"sewer20.c", "northwest");
add_exit(ROOMS+"sewer14.c", "south");
set("short", "City Sewers");
set("day long", "You are in the sewers of a once great city. Slug drips off the walls. This is where the stream seems to start. Water flows from a pipe over head. The sewer seems to split into many different directions.");
set("night long", "You are in the sewers of a once great city. Slug drips off the walls. This is where the stream seems to start. Water flows from a pipe over head. The sewer seems to split into many different directions.");
set_smell("default", "The cold wind feels like death on your skin");
set_listen("default", "sounds of rats fill the sewer tunnels.");
new(ITEM+"sewer_stream.c")->move(this_object());
set_pre_exit_functions( ({"north"}), ({"go_north"}));
}
void reset() {
 ::reset();
}
int go_north() {
   if(present("rat")) {
      if(this_player()->query_invis()) return 1;
      if(this_player()->query_ghost()) return 1;
      if(this_player()->query_hiding() >= 30) return 1;
      if(this_player()->query_stealth() >= 40) return 1;
      write("The rat-man pushes you back and shakes his head.");
      tell_room(this_object(), this_player()->query_cap_name() +
           " tried to go north, but was pushed back by the rat-man.",
          ({ this_player() }) );
      return 0;
      }
   else
      return 1;
}

