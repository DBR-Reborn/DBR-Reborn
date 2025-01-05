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
    add_exit(ROOMS+"ak_res2", "south");
    add_exit(ROOMS+"ak_haven1", "north");
    set("short","Devastation");
    set("long","Most magic guilds in cities are grouped together, partially out of convenience, but mostly out of fear that a lone, unopposed magician will wreak havoc upon an unguarded section of the city. This is one of those areas. What you see around you, the sheer devastation of the neighborhood, can only have come through a dedicated magical defense to a powerful army. You are surrounded by rubble, but the street continues south and north.");
}
