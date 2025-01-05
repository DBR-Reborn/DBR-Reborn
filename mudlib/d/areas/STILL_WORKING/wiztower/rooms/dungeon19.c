//Wiztower
//Dungeon19
// Coded by Glitch for DBR
// 07-10-00

#include <std.h>
#include "../wiztower.h"
inherit "/std/room";
object ob;

void create(){
   ::create();
   set_property("indoors",1);
   set("short", "A closet.");
   set("long", "You stand in a small walk-in closet. The room is rather plain.");
   set_items(([ ({ "room", "closet", "walk-in closet", "small walk-in closet" }) : "You're in it.",
      ]));
   add_pre_exit_function("out", "go_out");
   add_exit(ROOMS+"dungeon14","out");
}

int go_out() {
   if(this_player()->query_skill("perception")>=20) {
      write("You spot a trap and carefully avoid it.");
      say((this_player()->query_cap_name())+" carefully steps around a spot on the floor.");
      return 1;
   }
   write("You trigger a trap which %^RED%^EXPLODES%^RESET%^ with a boom.");
   (this_player()->add_hp(-75));
   return 0;
}
