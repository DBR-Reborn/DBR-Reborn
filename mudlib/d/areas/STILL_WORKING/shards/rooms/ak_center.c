
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
    add_exit(ROOMS+"ak_haven5", "east");
    add_exit(ROOMS+"ak_haven4", "west");
    add_exit(ROOMS+"ak_victory4", "south");
    add_exit(ROOMS+"ak_victory5", "north");
    add_exit(ROOMS+"ak_tower", "tower");
    set("short","Squared Circles");
    set("long","This is the center of Shards. A great tower stretches into the sky, most likely the one-time home of the town's council. It is kind of eerie to realize that at one point, thousands of people probably flocked around here, selling and buying. A profound sense of lonliness hits you.\n");
   add_item("tower","The tower reaches into the sky here.  It "+
       "is constructed from white marble and polished so that climbing it "+
       "would seem nearly impossible.\n");
}




