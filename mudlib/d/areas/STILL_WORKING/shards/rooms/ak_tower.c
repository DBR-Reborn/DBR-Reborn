#include "../shards.h"
inherit "std/room";

int chamber();
int read(string str);


void reset() {
  ::reset();
  if(!present("sphere"))
    new(OBJ+"crystal")->move(this_object());
}

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 3);
    add_exit(ROOMS+"ak_center", "out");
    set("short","The Tower");
    set("long","Amazingly, this tower still stands, despite the wreck and desolation around you. In the center of the room, you see a lone table - with a crystal sphere lying on it. The stairs going up have long fallen to bits, unfortunately.\n");
}
