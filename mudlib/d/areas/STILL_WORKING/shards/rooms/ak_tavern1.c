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
    add_exit(ROOMS+"ak_tavern2", "south");
    add_exit(ROOMS+"inn", "east");
    add_exit(ROOMS+"clan_shop", "west");
    set("short","At the north end of Tavern Street");
    set("long","You are at the north end of Tavern Street. How do you know this is Tavern Street? You don't, but it is a pretty good guess, considering the dozens of destroyed inns and bars around you. There is one inn still standing to your east, and a non-descript building to your west.");
    
}
