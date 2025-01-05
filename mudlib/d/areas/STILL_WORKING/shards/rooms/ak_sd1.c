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
    add_exit(ROOMS+"ak_sd2", "north");
    set("short","The Blood Trail");
    set("long","This is a dead end in the ruins of the town. Huge, unclimbable piles of rubble block your path in all directions but north. Someone must have taken great care to utterly annihilate the buildings, because there are none left standing around here.");
    
}
