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
  set("short","Pet cage.");
  set("long", "You see around you various pets of the mage. This probably is not a really safe spot.");
  add_exit(ROOMS+"wiztower6","down");
  add_exit(ROOMS+"wiztower8","east");
  add_exit(ROOMS+"wiztower9","west");
   add_exit(ROOMS+"wiztower10","up");
  set_items( ([ ({ "pet", "pets" }) : "Perhaps you should look at them.",
     "mage" : "Oh, he'll be made if you molest his pets.",
     "room" : "The one you're in.",
     ]) );
  new(MOBS+"p_dragon")->move(this_object());
  new(MOBS+"bat")->move(this_object());
  new(MOBS+"rat")->move(this_object());
  new(MOBS+"cat")->move(this_object());
}

