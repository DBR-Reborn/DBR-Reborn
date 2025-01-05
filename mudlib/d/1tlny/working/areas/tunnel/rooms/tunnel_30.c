#include <std.h>
#include "/wizards/delsius/defs/defs.h"
inherit ROOM;

void create() {
     ::create();
     set_property("indoors",1);
     set_property("light",-1);
     set("short", "Dark Tunnel");
     set("long", "The area surrounding you is virtually "
         "indistinguishable.  The tunnel walls glimmer with moisture and "
         "the ground is composed of small rocks and sand.  The constant "
         "flow of brisk air is almost enough to numb your senses.");
     set_smell("default", "You smell the decay of flesh and mildew in "
               "the air.");
     set_listen("default", "You hear the sound of wind howling through "
                "the tunnels.");
     set_items(([ ({"area","tunnel"}): "Due to the darkness, you can only "
                    "see a few feet in any direction.",
                  ({"wall","walls"}): "The tunnel walls are made of rock "]) );
     set_exits((["west":TUN_ROOMS+"tunnel_pool",
                 "southwest":TUN_ROOMS+"tunnel_39"]));
    add_pre_exit_function("west","go_west");
}

int go_west() {
   if(TP->is_player() || TP->is_pet() || TP->is_clone())
      return 1;
   else 
      return 0;
}
