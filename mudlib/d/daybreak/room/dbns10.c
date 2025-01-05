#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/virtual/room_8_9.world", "mountains");
    add_exit(ROOMS+"dbns9","south");
// Removed bad pathing to kuril from DBR to necromancer guild Tiny
    //add_exit("/d/nocte/kuril/rooms/entrance","east");
//Basic mapping added by Tiny 1/19/2020 
    set("short","Daybreak Valley Road");
    set("long",@ext Daybreak Valley Road runs north-south through Daybreak Ridge. 

    mountains
    |
    @
    |
    0
ext);
}
