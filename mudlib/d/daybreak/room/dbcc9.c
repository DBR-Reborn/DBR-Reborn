#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbcc4", "east");
    add_exit(ROOMS+"dbcc8","west");
//Basic mapping added by Tiny 1/19/2020
    set("short","Commerce Court");
    set("long","Commerce Court runs east-west through Daybreak Ridge.\n   \n    \n0--@--0\n    \n   \n");
}
