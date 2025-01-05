#include "../shards.h"
inherit "std/room";

void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("crystal")) {
      new(OBJ+"arch-mage_crystal")->move(this_object());
   }
}

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"ak_res1", "north");
    set("short","Magic Tricks");
    set("long","This must have been a library or a study hall at one point. Ripped pages, book covers, and all of the usual print paraphenalia litter the floor, covered in dust. Someone, or someones, took great trouble to utterly destroy this place in their search.");
}
