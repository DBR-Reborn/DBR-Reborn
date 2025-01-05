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
    add_exit(ROOMS+"ak_bless3", "west");
    add_exit(ROOMS+"ak_bless1","east");
    add_exit(ROOMS+"square", "south");
    set("short","Curses and Blessings");
    set("long","The desolation is overwhelming on this street, and you cannot help but feel... profaned. A long time ago, temples, churches, and places of worship all dotted the landscape, you realize. Now, the only building left standing is a cathedral to your east. ");
    
}
