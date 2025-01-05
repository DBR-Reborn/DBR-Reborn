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
    add_exit(ROOMS+"ak_victory4", "east");
    add_exit(ROOMS+"ak_haven4", "north"); 
    add_exit(ROOMS+"ak_shop4", "south");
    set("short","Southwest corner of the market");
    set("long","You are standing on the southwest corner of Market Square. There are shops to the south and west of you.  There would usually be salesmen offering you 'special deals', but they're long gone. \n" +
	"There are two signs here. ");
    add_item("sign 2", "This sign points west.\n\n"
"******************\n"
"  The Quest Room\n"
"******************\n");
  add_item("sign 1", "This sign points south.\n\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
"  The Adventurer's General Store\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

}
