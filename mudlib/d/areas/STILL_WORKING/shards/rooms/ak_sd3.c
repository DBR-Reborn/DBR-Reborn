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
    add_exit(ROOMS+"ak_sd2", "south");
    add_exit(ROOMS+"ak_egate", "north");
    add_exit(ROOMS+"fighter", "west");
    set("short","The Trail of Blood");
    set("long","Finally, after much walking, you find a building on this street which has not been totally demolished. To your west is a large headquarters of some sort. Maybe it was the defenders'? The street continues south, and the eastern gate of the town is north.");
    
}
