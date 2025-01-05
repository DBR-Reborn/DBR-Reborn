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
    add_exit(ROOMS+"arch-mage", "south");
    add_exit(ROOMS+"ak_res2", "north");
    add_exit(ROOMS+"enchanter", "east");
    set("short","The Magic Street");
    set("long","You are on the southern end of a street. The burned, unsafe remenants of many houses of magic surround you. You can see two buildings, though, which are still standing - one to the south, and one to the east.");
    
}
