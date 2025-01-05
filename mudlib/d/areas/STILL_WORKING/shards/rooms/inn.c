#include "../shards.h"
inherit "std/room";


void reset() {
  ::reset();
  if(!present("sphere"))
    new(OBJ+"inn_crystal")->move(this_object());
}

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"ak_tavern1", "west");
    set("short","Inn-side, Outside");
    set("long","This was at one time an inn, but it is now only a dimly-lit room with keys hanging on the wall. The stairs to the upstairs have long since collapsed, and there is now no way up. You ponder the fact that the keys are still around, and decide that the invaders probably just kicked the doors down. ");
}
