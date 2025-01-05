#include "../shards.h"
inherit "/std/vault";

private int open;

void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("crystal")) {
      new(OBJ+"magic_shop_crystal")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit(ROOMS+"ak_markse", "north");
   set("short","Magical Problems - Deadly Solutions");
   set("long",
"The sheer feeling of magic that radiates all around you is unmistakable. This feels like many of the magic shops you have been to in your travels. Unfortunately, the entire place has been cleaned of its wares - the only thing left is the door on the ground, beaten off its hinges.");
   set_items( (["wooden door" : "It looks very sturdy.",
              "south door" : "It is a large wooden door.",
              "door" : "Made of oak, and strong looking." ]) );
}
