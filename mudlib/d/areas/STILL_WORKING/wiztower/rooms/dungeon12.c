// Wiztower
// Dungeon12
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
   set("long", "You stand in a small cell. Manacles dangle from the east wall. Luckily they are currently empty. A small thin straw mat is in one corner of the room.");
   add_exit(ROOMS+"dungeon11", "west");
   set_items(([ ({ "cell", "small cell", "room" }) : "It's small and dirty.",
      ({ "doorway" }) : "It leads to the east.",
      ({ "stone walls", "stone wall","wall", "walls", "west wall" }) : "Your standard stone walls.",
      ({ "stone" }) : "It looks like limestone.",
      ({ "light", "dim light" }) : "The light spills in from the doorway.",
      ({ "manacle","manacles"}) : "The manacle looks strong, but is currently unoccupied.",
      ({ "mat", "straw mat", "thin straw mat" }) : "A place for a weary prisoner to rest.",
      ]));
   new(MOBS+"spider")->move(this_object());
   new(MOBS+"spider")->move(this_object());
}

