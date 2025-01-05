#include "../ruins.h"
#include <std.h>
inherit "std/room";
int search_count;

void create() {
::create() ;
set_property("indoors", 1);
set_property("light", 0);
add_exit(ROOMS+"sewer7.c", "west");
add_exit(ROOMS+"sewer4.c", "east");
set("short", "City Sewers");
set("day long", "You are in the sewers of a once great city. Slug drips off the walls. A stream running through the room bring water out of the city. There is a stream coming out of the northern wall.");
set("night long", "You are in the sewers of a once great city. Slug drips off the walls. A stream running through the room bring water out of the city. There is a stream coming out of the northern wall.");
set_smell("default", "The cold wind feels like death on your skin");
set_listen("default", "sounds of rats fill the sewer tunnels.");
new(ITEM+"sewer_stream.c")->move(this_object());
    set_search("northern wall",(: call_other, this_object(),"do_search" :));
    search_count=0;
set_pre_exit_functions( ({"north"}), ({"go_north"}));
set_pre_exit_functions( ({"west"}), ({"go_west"}));


}
void reset() {
 ::reset();
if(!present("rat"))
new(MON+"rat_adv_guard.c")->move(this_object());
}
void do_search() {
  int skill;
  object ob;
  string zplayer;
  say(this_player()->query_cap_name()+" appears to be looks for something on the northern wall.\n");
  skill=((int)this_player()->query_skill("perception"))-60;
  if((random(100)<skill) && search_count<1){
    search_count=1;
    write("Your search is successful.\n"+
      "You discovered a hidden passage.\n");
add_exit(ROOMS+"sewer6.c", "north");
  }
  else
    write("Your search yields nothing.");
  return;
}
int go_west() {
   if(present("rat")) {
      if(this_player()->query_invis()) return 1;
      if(this_player()->query_hiding() >= 30) return 1;
      if(this_player()->query_ghost()) return 1;
      if(this_player()->query_stealth() >= 40) return 1;
      write("The rat-man pushes you back and shakes his head.");
      tell_room(this_object(), this_player()->query_cap_name() +
           " tried to go west, but was pushed back by the rat-man.",
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
      if(this_player()->query_ghost()) return 1;
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
