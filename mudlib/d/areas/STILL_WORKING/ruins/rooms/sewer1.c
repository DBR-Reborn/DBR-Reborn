
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 1);
set_property("indoors", 1);
set("short", "City Sewers");
set("day long", "You are in the sewers of a once great city. Slug drips off the walls. A stream running through the room bring water out of the city. There is a ladder here which leads up to a manhole and the city above.");
set("night long", "You are in the sewers of a once great city. Slug drips off the walls. A stream running through the room bring water out of the city. There is a ladder here which leads up to a manhole and the city above.");
set_smell("default", "The cold wind feels like death on your skin");
set_listen("default", "sounds of rats fill the sewer tunnels.");
new(ITEM+"sewer_stream.c")->move(this_object());
set_exits( ([
"north" : ROOMS+"sewer3.c",
"ladder" : ROOMS+"ladder.c",
"south" : ROOMS+"sewer2.c",
]) );
set_pre_exit_functions( ({"ladder"}), ({"go_ladder"}) );
set_pre_exit_functions( ({"north"}), ({"go_north"}) );
}
void reset() {
 ::reset();
if(!present("rat"))
new(MON+"rat_guard.c")->move(this_object());
new(MON+"rat_guard.c")->move(this_object());
new(MON+"rat_guard.c")->move(this_object());
new(MON+"rat_guard.c")->move(this_object());
}
int go_ladder() {
   if(present("rat")) {
      if(this_player()->query_invis()) return 1;
      if(this_player()->query_hiding() >= 30) return 1;
      if(this_player()->query_ghost()) return 1;
      if(this_player()->query_stealth() >= 40) return 1;
      write("The rat-man pushes you back and shakes his head.");
      tell_room(this_object(), this_player()->query_cap_name() +
           " tried to climb the ladder, but was pushed back by the rat-man.",
           ({ this_player() }) );
      return 0;
      }
   else
      return 1;
}

int go_north() {
   if(present("rat")) {
      if(this_player()->query_invis()) return 1;
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

