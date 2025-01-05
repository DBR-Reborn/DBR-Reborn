// nwsecond

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "The northwest corner of the second floor");
    set("long", @ext You are standing at northwest side of the second. 
      floor of the mansion.  To the west is a ornately carved door, 
      and to the east and south you lie more balcony.

 0--@--0
    |
    0  
ext);
    add_exit("centersecond","east");
    add_exit("din4","west");
    add_exit("swsecond","south");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
