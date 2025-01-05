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
    add_exit(ROOMS+"ak_out4", "south");
    add_exit(ROOMS+"ak_victory2","north");
    set("short","Inside the southern gate of the town");
    set("long","A long time ago (you guess), this was the southern gate to the town. However, now there is no gate - it lies in a twisted mess on the ground. You can walk right out by going south. Guard shacks used to lie east and west, but they have been thoroughly demolished.");
}
