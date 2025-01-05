// Wiztower
// dungeon8
// Code by glitch for DBR
// 07-06-00

#include <std.h>
#include "../wiztower.h"

inherit "/std/room";

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 1);
  set("short","Dungeon");
  set("long", "You stand at the base of some stairs that lead back up into the dungeon. A passage leads to the north from here.  A couple torches light the area with a dim glow.");
   add_exit(ROOMS+"dungeon5","up");
  add_exit(ROOMS+"dungeon9","east");
  add_exit(ROOMS+"dungeon10", "west");
  add_exit(ROOMS+"dungeon11", "north");
  set_items( ([ ({ "room", "area" }) : "The area that you're in.",
     ({ "base", "base of stairs" }) : "The stairs lead upwards one level higher in the dungeon.",
     ({ "dungeon" }) : "A place to hold prisoners.",
     ({ "torch", "torches" }) : "They cast a dim light about the area.",
     ({ "light", "dim light" }) : "The light is issued by a couple torches mounted in brackets on the wall",
     ({ "wall", "stone wall", "plain stone wall" }) : "Plain stone walls.",
     ({ "bracket" }) : "They hold the torches",
     ]) );
  new(MOBS+"guard")->move(this_object());
}
