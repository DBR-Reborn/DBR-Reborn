//Wiztower
// Dungeon14
// Coded by Glitch
// For DBR 07-06-00

#include <std.h>
#include "../wiztower.h"
inherit "/std/room";

int a;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set("short", "a circular room");
   set("long", "You're in a circular room. Exits lead in all eight directions. In the center of the room is a pedastal");
   set_items(( [ ({ "room", "circular room" }) : "It is round. In the center is a pedastal.",
      ({ "center" }) : "A pedastal is here.",
      ({ "exit", "exits" }) : "All the exits are covered in a strange light blue glow, except the one you came through.",
      ({ "pedastal" }) : "The pedastal is carved from marble. There seems to be something on the top.",
      ({ "marble" }) : "It has fluted sides.",
      ({ "sides", "fluted sides" }) : "The flutes in the side of the pedestal were skillfully carved.",
      ({ "something" }) : "It's a button.",
    ]));
   add_exit(ROOMS+"dungeon13","east");
}

void init() {
   ::init();
   add_action("button_func","press");
}

int button_func(string str) {
   if(!str) { write("Press what?"); return 0; }
   if(str != "button") {write("Press what?");return 0;}
   remove_exit("east");
   write("You press the button and the room rotates!");
   say((this_player()->query_cap_name())+" presses on the pedestal and the room rotates.");
   a=(random(3)+1);
   if (a=1) {
      add_exit(ROOMS+"dungeon13","north");
      add_exit(ROOMS+"dungeon15","northeast");
      add_exit(ROOMS+"dungeon16","east");
      add_exit(ROOMS+"dungeon17","southeast");
      add_exit(ROOMS+"dungeon18","south");
      add_exit(ROOMS+"dungeon19","southwest");
      add_exit(ROOMS+"dungeon20","west");
      add_exit(ROOMS+"dungeon21","northwest");
      return 1;
   }
   if (a=2) {
      add_exit(ROOMS+"dungeon13","east");
      add_exit(ROOMS+"dungeon15","southeast");
      add_exit(ROOMS+"dungeon16","south");
      add_exit(ROOMS+"dungeon17","southwest");
      add_exit(ROOMS+"dungeon18","west");
      add_exit(ROOMS+"dungeon19","northwest");
      add_exit(ROOMS+"dungeon20","north");
      add_exit(ROOMS+"dungeon21","northeast");
      return 1;
   }
   if (a=3) {
      add_exit(ROOMS+"dungeon13","southeast");
      add_exit(ROOMS+"dungeon15","northwest");
      add_exit(ROOMS+"dungeon16","west");
      add_exit(ROOMS+"dungeon17","southwest");
      add_exit(ROOMS+"dungeon18","northeast");
      add_exit(ROOMS+"dungeon19","north");
      add_exit(ROOMS+"dungeon20","south0");
      add_exit(ROOMS+"dungeon21","east");
      return 1;
   }
}  
