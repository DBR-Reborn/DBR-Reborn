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
    add_exit(ROOMS+"war-priest", "north");
    add_exit(ROOMS+"hospital", "south");
    add_exit(ROOMS+"ak_victory8", "west");
    add_exit(ROOMS+"ak_bless2","east");
    set("short","Blessings in Disguise");
    set("long",
	"Walking along the street, you spot a surprise in all of the rubble. To your north, a small temple of some sort remains standing, dwarfed in size by the cathedral, but in considerably better shape. You hardly noticed it before you walked right up before it. Odd.");
}
