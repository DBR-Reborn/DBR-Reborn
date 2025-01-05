
#include <def.h>
//inherit LOGGER;
inherit "std/room";

void create() {
     ::create();
     set_property("outdoors", 1);
     set_property("light", 2);
     set_smell("default", "There is a slight odor of sulfur in the air.");
     set("short", "A huge crack in the ground");
     set("long",
         "There is a giant opening in the ground and you see smoke rising from it.  You might be able to climb down it.\n"
     );

     set_items( ([ "crack": " The crack seems to go down forever." ]) );
     add_exit("dm2", "down");
    add_exit("/d/damned/virtual/room_22_15.world", "out");
}
/*
void init() {
int log;
     ::init();
     log = monitor();
}
*/
