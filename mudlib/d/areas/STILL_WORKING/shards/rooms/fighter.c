#include "../shards.h"
inherit "std/room";


void reset() {
  ::reset();
  if(!present("sphere"))
    new(OBJ+"fighter_crystal")->move(this_object());
}

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"ak_sd3", "east");
    set("short","The Militia Headquarters");
    set("long","You are sickened as you walk in by the sight of a skeleton hanging from a hook on the wall. As you rip your eyes away from the horrific sight, you are confronted by something even worse: dozens of bodies, just like that one. You feel your stomach heave. The remenants of armor on the corpses suggest that this was the central militia headquarters, and that someone did not particularly like them.");
}
