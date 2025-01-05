// Wiztower
// Dungeon13
// Coded by Glitch for DBR
// 07-05-00

#include <std.h>
#include "../wiztower.h"

inherit "/std/room";

void create(){
   ::create();
   set_property("indoors", 1);
   set_property("light", 1);
   set("short", "a cell");
   set("long", "You stand in a small cell. Manacles dangle from the west wall. Luckily they are currently empty. A small thin straw mat is in one corner of the room.");
   add_exit(ROOMS+"dungeon11","east");
   set_items(([ ({ "cell", "small cell", "room" }) : "It's small and dirty.",
      ({ "doorway" }) : "It leads to the east.",
      ({ "stone walls", "stone wall","wall", "walls" }) : "Which wall?",
      ({ "stone" }) : "It looks like limestone.",
      ({ "light", "dim light" }) : "The light spills in from the doorway.",
      ({ "manacle","manacles"}) : "The manacle looks strong, but is currently unoccupied.",
      ({ "mat", "straw mat", "thin straw mat" }) : "A place for a weary prisoner to rest.",
      ({ "west wall" }) : "The wall has some worn spots.",
      ({ "spots", "worn spots" }) : "For some reason those spots seem to have seen a lot of use",
      ]));
   new(MOBS+"rat")->move(this_object());
   new(MOBS+"rat")->move(this_object());
   new(MOBS+"rat")->move(this_object());
   new(MOBS+"rat")->move(this_object());
}

void init() {
   ::init();
   add_action("search_fun", "search");
   }
   
int search_fun(string str){
   if (!str) {
   write("What are you trying to search?");
   return 0;
   }
   if (str != "spots") {
   write("What are you trying to search?");
   return 0;
   }
   if((this_player()->query_skill("perception"))>=25) {
      write("You find a secret entrance!");
      add_exit(ROOMS+"dungeon14.c","west");
      say((this_player()->query_cap_name())+" searches about and reveils a secret entrance!");
      return 1;
   }
   write("Your search reveals squat.");
   say((this_player()->query_cap_name())+ " searches about in vain.");
   return 0;
}
