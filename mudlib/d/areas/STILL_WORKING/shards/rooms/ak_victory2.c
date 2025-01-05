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
    add_exit(ROOMS+"ak_sgate", "south");
    add_exit(ROOMS+"ak_victory3", "north");
    set("short","The Street of Defeat");

    set("long","It only takes a quick look to see that a great battle occured here. Tens of bodies are scattered about the place, most still in armor. Here and there, you spot a spell-caster's robe, torn and shred to bits. The street continues north, and the town gates are south.");
}
