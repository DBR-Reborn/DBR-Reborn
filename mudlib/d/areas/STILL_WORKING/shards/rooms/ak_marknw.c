#include "../shards.h"
inherit "std/vault";

void reset() {
        ::reset();
        if(!present("demon"))
  new(MON+"demon")->move(this_object());
        }

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"ak_shop1", "west");
    add_exit(ROOMS+"ak_victory5", "east");
    add_exit(ROOMS+"ak_haven4", "south");
    set("short","Northwest corner of Market Square");
    set("long","You are standing on the northwest corner of Market Square. There are shops to the north and west of you. Well, at least to the west - the one to the north appears to have been razed to the ground.  Noisy men would probably be trying to get you inside the western shop, but your cold steel would have silenced them!");
    add_item("sign", "This sign points west.\n"
"******************\n"
"  The Moneychanger\n"
"******************\n");
}
