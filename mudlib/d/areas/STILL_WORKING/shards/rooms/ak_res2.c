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
    add_exit(ROOMS+"ak_res1", "south");
    add_exit(ROOMS+"ak_res3", "north");
    add_exit(ROOMS+"ak_lib", "west");
    set("short","Alone");
    set("long","All the buildings on this street, except for the library to your west, have been levelled by what appears to be a combination of magic and brute force. The silence is horrible, and your thoughts turn into nightmares of what must have happened here.\n");
    
}
