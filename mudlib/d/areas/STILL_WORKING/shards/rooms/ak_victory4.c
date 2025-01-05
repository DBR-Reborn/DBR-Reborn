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
    add_exit(ROOMS+"ak_victory3", "south");
    add_exit(ROOMS+"ak_center", "north");
    add_exit(ROOMS+"ak_marksw", "west"); 
    add_exit(ROOMS+"ak_markse", "east");
    set("short","The South Side of Market Square");
    set("long","This must have been the market square at one point. The quiet is eerie, and disconcerting. What could have silenced this place? The road goes south here, and the square expands in all other directions.");

}
