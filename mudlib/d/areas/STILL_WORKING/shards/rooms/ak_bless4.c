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
    add_exit(ROOMS+"ak_slum1", "west");
    add_exit(ROOMS+"ak_victory8","east");
    set("short","The Way of Blessing");
    set("long","Even though this entire city has been destroyed, some parts are in better shapes than others. It is quite obvious that to your west is one of those parts that has been destroyed even _more_ than the others. You can go east and stay in safe(r) territory.");
    
}
