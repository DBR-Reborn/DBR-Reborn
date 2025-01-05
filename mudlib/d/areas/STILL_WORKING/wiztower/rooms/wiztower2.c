// wiztower   2     //
// Coded by Glitch  //
// 06-20-00         //
// for DBR          //
//////////////////////

#include <std.h>
#include "../wiztower.h"

inherit "/std/room";

void create() {
   ::create();
   set_property("indoors", 1);
   set_property("light", 1);
   set("short", "Top of stairs.");
   set("long", "You stand at the top of a set of stairs.  The room here is impossibly large in comparison to what you observed from the outside. This is impossible. This much space just can't fit within a 15 foot round tower.");
   add_exit(ROOMS+"wiztower1","down");
   add_exit(ROOMS+"wiztower3", "east");
   add_exit(ROOMS+"wiztower4", "west");
   add_exit(ROOMS+"wiztower5", "south");
   set_items( ([ ({ "stairs", "set of stairs", "top of stairs" }) : "You stand at the top of some stairs. They lead down to the entry hall.",
      ({ "entry hall", "hall" }) :  "It's down below you.",
      ({ "tower" , "round tower" }) : "The one you're in right now."
      ]) );
}

