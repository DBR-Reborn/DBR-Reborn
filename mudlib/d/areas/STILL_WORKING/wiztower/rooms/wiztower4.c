// wiztower   4     //
// Coded by Glitch  //
// 06-21-00         //
// for DBR          //
//////////////////////

#include <std.h>
#include "../wiztower.h"

inherit "/std/room";

void create() {
   ::create();
   set_property("indoors", 1);
   set_property("light", 1);
   set("short", "Living Area.");
   set("long", "You've enter what has to be the living area of the tower. A couch sits near the west wall. A smallish table is cluttered with odds and ends in front of the couch. A small fireplace on the south wall gives the room a cheery light.");
   add_exit(ROOMS+"wiztower2","east");
   
   set_items( ([ ({ "area", "living area" }) : "This seems to be the living area. It's hard to tell if it gets much use.",
      ({ "wall", "west wall" }) : "On the wall hangs a nice tapestry depicting a country-side scene.",
      ({ "table","smallish table" }) : "The table is near the couch.",
      ({ "fireplace", "small fireplace" }) : "The fireplace is small, but emits a good deal of light and heat.",
      ({ "couch" }): "The couch is quite big and looks like comfortable place to sit.",
      ]) );
}
void init(){
   ::init();
   add_action("couch_func", "sit");
}

int couch_func(string str){
   if (str != "couch") {
      say("Yo, where are you sitting bud?");
      write((this_player()->query_cap_name())+ "tries to sit on the " +str+" but, stands right back up.");
      return 0;
   }
   say("You sit on the couch.");
   write(this_player()->query_cap_name()+" sits on the couch.");
   return 1;
}

