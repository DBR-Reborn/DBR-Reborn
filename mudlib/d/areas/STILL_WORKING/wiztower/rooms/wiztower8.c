//Wiztower 7
// Coded by Glitch for DBR
// 06-28-00

#include <std.h>
#include "../wiztower.h"

inherit "std/room";

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 1);
  set("short","Storage room.");
  set("long", "This is a cluttered storage room. Crates and boxes lay scattered about the room.");
  add_exit(ROOMS+"wiztower7","west");
  set_items( ([ ({ "room", "storage room", "here" }) : "The room you're in.",
     ({ "crate", "crates", "box", "boxes"}) : "They lay scattered about the room.",
     ]) );
}


