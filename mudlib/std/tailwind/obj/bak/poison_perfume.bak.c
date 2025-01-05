/*
  Vial that holds weapon poison created by players when they use
  the Poison Lore skill.  This object is created by a plant press
  and should not be created by any other object or bad things may
  happen.
 
  Duridian 4/1/96

  Modified by Tailwind for the Alchemist Guild

  Tailwind 5/22/99

*/
 
#include <std.h>
 
inherit "/std/Object";

void create() {
   ::create();


   set_name("perfume");
   set_id( ({"poison perfume", "poisonous perfume", "deadly perfume", "perfume"}) );
   set_short("a jar of poison perfume");
   set_long("A small jar containing poison perfume. You can apply it, but it won't do anything... it needs magic activation.");
   set_weight(3);
   set_value(0);
}
 
void init() {
   ::init();
   add_action("drink_func", "apply");
}

int drink_func(string str) {
   object ob;
 
   if((!str) || ((str != "deadly perfume") && (str != "poisonous perfume") && (str != "poison perfume") && (str != "perfume"))) {
      notify_fail("Apply what?\n");
      return 1;
   }
 
   if(this_player()->query_current_attacker()) {
      write("You cannot do that while in combat!");
      return 1;
   }
 

   write("You apply "+query_short()+" to your skin and nothing happens");
   
   message("info", (string)this_player()->query_cap_name() +
      " applies "+query_short()+" to the skin, but nothing happens.!",
      all_inventory(environment(this_player())), ({ this_player() }) );
   remove();
   return 1;
}
