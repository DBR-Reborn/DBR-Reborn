// wiztower   1     //
// Coded by Glitch  //
// xx-xx-00         //
// for DBR          //
//////////////////////

#include <std.h>
#include "../wiztower.h"

inherit "/std/room";

void create() {
   ::create();
   set_property("indoors", 1);
   set_property("light", 1);
   set("short", "Entry Chamber.");
   set("long", "You've entered the entery chamber of a tower. All about you is dust and dirt from countless years accumulation. An old table leans on unsteady legs.");
   add_exit("/d/damned/virtual/room_2_9.world","out");
   add_exit(ROOMS+"wiztower2", "up");
   set_items( ([ ({"chamber", "entry chamber" }) : "The one you're in. It is covered in deep dust and debris from years of accumulation.",
      ({ "dust", "debris",  "dirt" }) : "The dust is deep and mouldering leaves and other detrius lay about the chamber.",
      ({ "table", "old table" }) : "The table leans drunkenly on unsteady legs.",
      ({ "leg", "legs" }) : "One of the legs looks like it is about to fall off.",
      ]) );
}

void init(){
   ::init();
   add_action("search_fun","search");
}

int search_fun(string str){
   if (!str) {
      write("What da heck ya want to search?");
      return 0;
   }
   if (str != "dust") {
      write("It's very intresting, but you find nothing.");
      say((this_player()->query_cap_name())+" searches around the " +str+", but finds nothing of intrest.");
      return 0;
   }
   write("You search the dust and find a trapdoor leading down.");
   say((this_player()->query_cap_name())+ " searchs the dust and locates a trap door!");
   add_exit(ROOMS+"dungeon1","down");
   return 1;
}
