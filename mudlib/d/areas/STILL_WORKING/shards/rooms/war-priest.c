#include "../shards.h"
inherit "std/room";


void reset() {
  ::reset();
  if(!present("sphere"))
    new(OBJ+"wp_crystal")->move(this_object());
}

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"ak_bless3", "south");
    set("short","The Temple");
    set("long","Surprisingly, the interior of this Temple of Taul is pretty much intact. . A huge mace is engraved into the northern wall, showing that this was a war-priest guild at one point. The altar is still in the center of the room, and that feeling of sacredness still floats in the air.");
}
