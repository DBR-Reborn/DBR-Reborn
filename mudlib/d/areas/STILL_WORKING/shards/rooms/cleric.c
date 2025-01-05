#include "../shards.h"
inherit "std/room";


void reset() {
  ::reset();
  if(!present("sphere"))
    new(OBJ+"cleric_crystal")->move(this_object());
}

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"ak_bless1", "west");
    set("short","The Cathedral");
    set("long","At some point in time, this building was probably awe-inspiring in size and decoration. Even now, you can see the genius architectural design of the Cathdedral. It is a shame that it was destroyed. Holiness radiates around you.");
}
