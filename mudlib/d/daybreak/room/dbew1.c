#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/virtual/room_8_9.world", "mountains");
    add_exit(ROOMS+"dbew2","west");
//Basic mapping added by Tiny 1/19/2020
    set("short","Main Street");
    set("long",@ext Main Street runs east-west through Daybreak Ridge.

 0--@--mountains
ext);
}
