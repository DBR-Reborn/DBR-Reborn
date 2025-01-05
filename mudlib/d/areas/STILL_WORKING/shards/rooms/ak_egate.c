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
    add_exit(ROOMS+"ak_haven7", "west");
    add_exit(ROOMS+"ak_out3", "east");
    add_exit(ROOMS+"ak_sd3", "south");
    add_exit(ROOMS+"ak_sd4", "north");
    set("short","Inside the eastern gate of the town");
    set("long","A long time ago (you guess), this was the eastern gate to the town. However, now there is no gate - it lies in a twisted mess on the ground. You can walk right out by going east. A street also runs north and south.");

}
