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
    add_exit(ROOMS+"ak_tavern2", "north");
    add_exit(ROOMS+"mine_shop", "east");
    add_exit(ROOMS+"ak_haven1", "south");
    set("short","Drinking Life");
    set("long","This section of town was hit badly by whatever attacked this town. Most of the taverns and inns which used to line this street (you can tell from the debris that that's what most of the shops were) have been sacked and burned to the ground. A lone shop still stands to the east. You wonder what makes it different than the rest.");
    
}

