// Wiztower
// Dungeon5
// Coded by Glitch for DBR
// 07-05-00

#include <std.h>
#include "../wiztower.h"

inherit "/std/room";

void create(){
   ::create();
   set_property("indoors", 1);
   set_property("light", 1);
   set("short", "a hall");
   set("long", "You stand in a short hallway. Doorways lead to the east and west. Torches in brackets on the walls provide dim light.");
   add_exit(ROOMS+"dungeon8","down");
   add_exit(ROOMS+"dungeon6","east");
   add_exit(ROOMS+"dungeon7", "west");
   add_exit(ROOMS+"dungeon2","north");
   set_items(([ ({ "hallway", "short hallway" }) : "The hallway leads to the stairs to the north and further south. Exits lead east and west from here",
      ({ "doorway", "doorways" }) : "They lead east and west.",
      ({ "bracket", "brackets" }) : "They hold the torches.",
      ({ "torch", "torches" }) : "The torches give off a dim light.",
      ({ "stone walls", "stone wall","wall", "walls" }) : "Your standard stone walls.",
      ({ "stone" }) : "It looks like limestone.",
      ({ "light", "dim light" }) : "It's being given off by the torches.",
      ]));
   new(MOBS+"guard")->move(this_object());
}
