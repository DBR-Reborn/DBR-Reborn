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
    add_exit(ROOMS+"ak_tavern1", "north");
    add_exit(ROOMS+"ak_tav", "east");
    add_exit(ROOMS+"ak_tavern3", "south");
    set("short","Midst of Tavern Street");
    add_exit(ROOMS+"castle_shop", "west");
    set("long", "You are in the midst of the 'Tavern Street'. To your east is a partially-destroyed tavern, and to the west is a large building of some sort.\n");
    
}
