#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
int    amt;
object money;
::create() ;
set_property("light", 0);
set_property("indoors", 1);
add_exit(ROOMS+"sewer8.c", "west");
set("short", "hinden passage");
set("long", "You are in a hind passage. Slug drips off the walls. A stream running through the room bring water out of the city. This seems to be a treasury room.");
set_smell("default", "The cold wind feels like death on your skin");
set_listen("default", "sounds of rats fill the sewer tunnels.");
new(ITEM+"sewer_stream.c")->move(this_object());
amt = random(10)*50+100;
    money = new("std/obj/coins");
money->set_money("silver",amt);
    money->move(this_object());
   set_pre_exit_functions( ({"west"}), ({"go_west"}) );

}
void reset() {
 ::reset();
if(!present("statue"))
new(MON+"sewer_statue.c")->move(this_object());
}
int go_west() {
   if(present("statue")) {
      if(this_player()->query_invis()) return 1;
      if(this_player()->query_ghost()) return 1;
      if(this_player()->query_hiding() >= 30) return 1;
      if(this_player()->query_stealth() >= 40) return 1;
        write("The cat-man pushes you back and shakes his head.");
      tell_room(this_object(), this_player()->query_cap_name() +
           " tried to go west, but was pushed back by the rat-man.",
          ({ this_player() }) );
      return 0;
      }
   else
      return 1;
}


