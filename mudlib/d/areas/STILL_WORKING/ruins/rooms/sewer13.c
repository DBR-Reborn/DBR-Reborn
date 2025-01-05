#include "../ruins.h"
#include <std.h>
inherit "std/room";
int search_count;
void create() {
::create() ;
set_property("light", 0);
set_property("indoors",1);
// add_exit(ROOMS+"rathome11.c", "ladder");
add_exit(ROOMS+"sewer12.c", "east");
set("short", "City Sewers");
set("day long", "You are in the sewers of a once great city. Slug drips off the walls. A stream running through the room bring water out of the city. The stream seems to stop right in the middle of the room.");
set("night long", "You are in the sewers of a once great city. Slug drips off the walls. A stream running through the room bring water out of the city. The stream seems to stop right in the middle of the room.");
set_smell("default", "The cold wind feels like death on your skin");
set_listen("default", "sounds of rats fill the sewer tunnels.");
new(ITEM+"sewer_stream.c")->move(this_object());
set_pre_exit_functions( ({"ladder"}), ({"go_ladder"}));
set_search("floor",(: call_other, this_object(),"do_search":));
}
void reset() {
 ::reset();
if(!present("rat"))
new(MON+"shadow_rat.c")->move(this_object());
new(MON+"shadow_rat.c")->move(this_object());
new(MON+"shadow_rat.c")->move(this_object());
new(MON+"shadow_rat.c")->move(this_object());
new(MON+"shadow_rat.c")->move(this_object());
}
void do_search() {
  int skill;
  object ob;
  string zplayer;
  say(this_player()->query_cap_name()+" appears to be looks for something on the floor.\n");
  skill=((int)this_player()->query_skill("perception"))-60;
  if((random(100)<skill) && search_count<1){
    search_count=1;
    write("Your search is successful.\n"+
"You discovered a hole in the floor. But the hole seems to be blocked for now. Though it looks like the water will back the blockage very soon.\n");
//      "You discovered a hole in the floor.\n");
// add_exit(ROOMS+"rathome11", "ladder");
  }
  else
    write("Your search yields nothing.");
  return;
}
int go_ladder() {
   if(present("rat")) {
      if(this_player()->query_invis()) return 1;
      if(this_player()->query_ghost()) return 1;
      if(this_player()->query_hiding() >= 30) return 1;
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
