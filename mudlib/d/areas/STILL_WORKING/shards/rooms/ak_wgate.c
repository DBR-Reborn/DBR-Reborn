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
    add_exit(ROOMS+"ak_out1", "west");
    add_exit(ROOMS+"ak_haven1","east");
    set("short","Inside the western gate of the town");
    set("long","A long time ago (you guess), this was the western gate to the town. However, now there is no gate - it lies in a twisted mess on the ground. You can walk right out by going west.");

}
