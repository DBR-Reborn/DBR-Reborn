#include "../ruins.h"
#include <std.h>
inherit "std/room";
int search_count;

void create() {
::create() ;
set_property("light", 0);
set_property("night light",0);
set_property("indoors", 1);
add_exit(ROOMS+"sewer8.c", "north");
set("short", "hinden passage");
set("long", "You are in a hind passage. Slug drips off the walls. A stream running through the room bring water out of the city. There is a stream that leads into the southern wall.");
set_smell("default", "The cold wind feels like death on your skin");
set_listen("default", "sounds of rats fill the sewer tunnels.");
new(ITEM+"sewer_stream.c")->move(this_object());
    set_search("southern wall",(: call_other, this_object(),"do_search" :));
    search_count=0;

}
void do_search() {
  int skill;
  object ob;
  string zplayer;
  say(this_player()->query_cap_name()+" appears to be looks for something on the southern wall.\n");
  skill=((int)this_player()->query_skill("perception"))-60;
  if((random(100)<skill) && search_count<1){
    search_count=1;
    write("Your search is successful.\n"+
      "You discovered a hidden passage.\n");
add_exit(ROOMS+"sewer5.c", "south");
  }
  else
    write("Your search yields nothing.");
  return;
}
