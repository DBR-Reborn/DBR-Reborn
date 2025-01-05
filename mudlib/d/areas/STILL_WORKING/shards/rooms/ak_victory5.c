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
    add_exit(ROOMS+"ak_victory6", "north");
    add_exit(ROOMS+"ak_center", "south");
    add_exit(ROOMS+"ak_marknw", "west"); 
    add_exit(ROOMS+"ak_markne", "east");
    set("short","The North Side of the Market Square");
    set("long", "This must have been the market square at one point. The quiet is eerie, and disconcerting. What could have silenced this place? A road goes north here, and the square expands in all other directions.");

}
