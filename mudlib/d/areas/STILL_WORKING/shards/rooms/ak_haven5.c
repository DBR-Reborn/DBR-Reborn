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
    add_exit(ROOMS+"ak_haven6", "east");
    add_exit(ROOMS+"ak_center", "west");
    add_exit(ROOMS+"ak_markne", "north"); 
    add_exit(ROOMS+"ak_markse", "south");
    set("short","The Eastern side of Market Square");
    set("long","This must have been the market square at one point. The quiet is eerie, and disconcerting. What could have silenced this place? The main road is east of here, and the square expands in all other directions.");

}
