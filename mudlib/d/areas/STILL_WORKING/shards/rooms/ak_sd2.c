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
    add_exit(ROOMS+"ak_sd1", "south");
    add_exit(ROOMS+"ak_sd3", "north");
    set("short","Bloody Trail");
    set("long","The number of bodies here, oddly enough, is even higher than the rest of the city. You guess that the city's fighting guilds were located here. They didn't fight well enough, you judge. The street continues north and south.\n");
    
}
