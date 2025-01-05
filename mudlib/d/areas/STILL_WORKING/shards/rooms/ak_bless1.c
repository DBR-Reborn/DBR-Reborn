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
    add_exit(ROOMS+"cleric", "east");
    add_exit(ROOMS+"ak_bless2","west");
    set("short","On Blessing Way, East of the Cathedral");
    set("long","As you walk down this long-abandoned street, a sign on the ground catches your eye. It has 'Blessing Way' printed upon it. To your east is the destroyed remenant of a cathedral.");
}
