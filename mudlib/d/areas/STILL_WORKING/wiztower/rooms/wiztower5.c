// wiztower   5     //
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
   set("short", "Water Closet.");
   set("long", "This smallish room is a water closet.  Water runs into the room through a small pipe in the south wall. It then runs through a trough to a small drain pipe. Over the trough is a small bench with a circular hole cut out.");
   add_exit(ROOMS+"wiztower2","north");
   set_items( ([ ({ "room", "smallish room", "water closet" }) : "A bathroom you dolt!",
      ({ "bathroom" }) :  "Otherwise known as a water closet.",
      ({ "water" }) : "Runs in through the pipe and through the trough to the drain pipe.",
      ({ "pipe" }) : "Which one? The small pipe, or the drain pipe?",
      ({ "small pipe" }) : "The pipe is really small.  Only about 3 inches in diameter.",
      ({ "drain pipe" }) : "The drain pipe seems to drain down to somewhere below the tower. For some reason, the edges of the drain pipe seem blurry.",
      ({ "edge", "edge of the pipe" }) : "It is blurry, possibly illusionary.",
      ({ "trough" }) : "The trough channels the flow of water through the water closet.",
      ]) );
}
void init() {
   ::init();
   add_action("search_fun", "search");
   }
int search_fun(string str) {
   if (str != "drain") {
      write("Search though you might, you find nothing at all.");
      say((this_player()->query_cap_name()) + " searches the " + str + " but, comes up empty.");
      return 0;
      }
   write("Hey! That drain is an illusion. It is actually more than big enough to allow you passage.");
   say((this_player()->query_cap_name()) + " searches the drain and shows you an exit!");
   add_exit(ROOMS+"wiztower6","drain");
   return 1;
}
