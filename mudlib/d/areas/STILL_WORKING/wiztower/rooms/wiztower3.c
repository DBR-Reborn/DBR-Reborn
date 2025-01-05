// wiztower   3     //
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
   set("short", "Kitchen.");
   set("long", "You've stepped in to a clean and orderly kitchen area. A large, sturdy table dominates the center of room. A huge fireplace has a large cauldren bubbling away under a gentle flame.");
   add_exit(ROOMS+"wiztower2","west");
   
   set_items( ([ ({ "kitchen", "area", "kitchen area", "room" }) : "The kitchen is clean.",
      ({ "table", "large table", "sturdy table", "large sturdy table" }) : "The table is clean and very solidly constructed. On the table you see plate of fine china, and a gold trimmed set of silverware.",
      ({ "center", "center of the room" }) : "The table is here.",
      ({ "fireplace", "huge fireplace" }) : "The fireplace is very big and a cheerful looking fire is blazing away under a bubbling cauldren.",
      ({ "cauldren", "bubbling cauldren" }) : "The cauldren seems made of copper and a thick liquid bubbles inside it.",
      ({ "liquid", "thick liquid" }) : "The liquid seems to be some sort of rich looking stew.",
      "stew" : "It looks good.",
      ({ "flame", "gentle flame" }) : "The flame dances a merry jig under the bubbling cauldren weaving a hypnotic pattern.",
      ({ "pattern", "hypnotic pattern" }) : "The flames seem to form dancing men and women who seem to becon you to join them.",
      ({ "men", "dancing men" }) : "They seem to be urging you to join them.",
      ({ "women", "dancing women" }) : "They suductively urge you to join them in the flame.",
      ]) );
}
void init(){
   ::init();
   add_action("flame_func", "step");
}

int flame_func(string str){
   if (str != "flame") {
      say("Yo, where are you stepping to bud?");
      write((this_player()->query_cap_name())+ "tries to step to " +str+" but, goes nowhere.");
      return 0;
   }
write((this_player()->query_cap_name())+" tries to step into the flames but is pushed back by something as it emerges from the flames.");
say("You try to step into the fire, but are shoved back into the room by something.");

   new(MOBS+"flame_ele")->move(this_object());
   return 1;
}
