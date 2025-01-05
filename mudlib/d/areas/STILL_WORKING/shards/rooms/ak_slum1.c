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
    add_exit(ROOMS+"ak_slum3", "north");
    add_exit(ROOMS+"ak_slum2", "south");
    add_exit(ROOMS+"ak_bless4", "east");
    set("short","Inside the Slums");
    set("long","As incredible as it may seem, this part of Shards is even more destroyed than the rest of the town. Pretty much every building has been razed to the ground, and the area is so lifeless that not even rats or insects crawl about.");
}
