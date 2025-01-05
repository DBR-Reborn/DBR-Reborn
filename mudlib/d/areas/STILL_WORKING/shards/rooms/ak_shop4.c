#include "../shards.h"
inherit "/std/vault";


void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("crystal")) {
      new(OBJ+"general_store_crystal")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit(ROOMS+"ak_marksw", "north");
   set("short","The Dead Depot");
   set("long",
"A long time ago, this must have been a supply depot or store of some sort. All sorts of tools and utensils rust away on the ground, completely uselss to you. The wall between the main storage room and this room has collapsed, but you see nothing in the stores, either.");
   set_items( (["tools":"Some of this stuff could have been pretty useful.",
              "utensils" : "Forks, knives, and spoons, you know, that stuff you never use."]) );
}
