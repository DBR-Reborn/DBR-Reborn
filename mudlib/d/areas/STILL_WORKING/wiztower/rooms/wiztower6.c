// wiztower   6     //
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
   set("short", "Drain pipe.");
   set("long", "You've entered the drain pipe. It's suprisingly roomy in here. A small outlet allows the water to drain while leaving your feet clean and dry. Soft light is issued by fungus on the ceiling.");
   add_exit(ROOMS+"wiztower5","out");
   add_exit(ROOMS+"wiztower7", "up");
   set_items( ([ ({ "drain", "drain pipe" }) : "The one you're in.",
      ({ "small outlet", "outlet" }) :  "It lets the water drain out.",
      ({ "water" }) : "The water runs in from the water closet and out the outlet.",
      ({ "water closet" }) : "Get out of here if you really want to see that.",
      ({ "fungus" }) : "The fungus emits a gentle light.",
      ]) );
}


