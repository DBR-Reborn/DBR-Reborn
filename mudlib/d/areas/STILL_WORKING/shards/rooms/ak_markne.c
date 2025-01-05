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
    add_exit(ROOMS+"ak_victory5", "west");
    add_exit(ROOMS+"ak_shop7", "east");
    add_exit(ROOMS+"ak_shop8", "north");
    add_exit(ROOMS+"ak_haven5", "south");
    set("short","Northeast corner of Market Square");
    set("long","You are standing on the northeast corner of Market Square. There are shops to the north and east of you.  You can kind of imagine that it would be more quiet here, as storekeepers tend to shoo pushcart merchants away from their shops.\n" +
	"There are two signs here, hanging from the shops. ");
    add_item("sign 1", "This sign points north.\n"
"*********************\n"
" The Armoursmith Shop\n"
"*********************\n");
    add_item("sign 2", "This sign points east.\n"
"**************************\n"
"   The Weaponsmith Shop\n"
"**************************\n");
    return;
}

