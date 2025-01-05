//Wiztower
//Dungeon15
// Coded by Glitch for DBR
// 07-06-00

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
   add_exit(ROOMS+"dungeon14","out");
   ob = new("/d/damned/virtual/dagger_6.weapon");
   ob->move(this_object());
   ob->set_material("mabril");
}
