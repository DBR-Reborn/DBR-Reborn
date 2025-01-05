#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbew9", "east");
    add_exit("/d/damned/virtual/room_8_9.world","mountains");
    add_exit(ROOMS+"dbvl1", "south");
//Basic mapping added by Tiny 1/19/2020
    set("short","Main Street");
    set("long",@ext Main Street runs east-west through Daybreak Ridge

mountains--@--0
           |
           0
ext);
}
