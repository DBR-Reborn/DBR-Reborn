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
    add_exit(ROOMS+"ak_haven6", "west");
    add_exit(ROOMS+"ak_egate", "east");
    set("short","Wartorn");

    set("long", "The sheer destruction of the town amazes you as you walk along a main street. Houses by the dozens have been razed to the ground, and skeletons litter the streets. Rusted armor still lies on the ground. The street continues east. The gate is to your east.");
}
