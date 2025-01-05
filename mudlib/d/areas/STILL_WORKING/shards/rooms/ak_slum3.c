#include "../shards.h"
inherit "std/room";

void reset() {
        ::reset();
        if(!present("demon"))
  new(MON+"demon")->move(this_object());
        }

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"ak_slum1", "south");
    set("short","Dead end in the Slums");
    set("long","You are in a coincidental alleyway. When referring to coincidental, it means that the only reason it is an alleyway at all is because you are surrounded on two sides by massive piles of rubble, and on another by a dilapidated building. You can get out of here by going south.");
}
