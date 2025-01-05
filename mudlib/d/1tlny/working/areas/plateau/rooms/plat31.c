
#include <std.h>
#include </wizards/garetjax/plateau/defs.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("outdoors", 1);
    set("short", "The Savanah Plateau");
   set_long( "\nYou are on a grassy plateau which stretches out in "
   "all directions. The ground seems to slant towards the middle of the "
   "plateau, and you can see off in the direction of the center, a dark tower."
    " There is a large horse turd here, which you just barely avoided stepping in."
     " The entrance to a small centaur nursery is here."
    );
    set_exits( ({  "plat40.c", "plat32.c", "plat30.c", "plat26.c", "nursery1.c"}),
      ({"north", "east", "west", "south", "nursery" })
    );
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "The"  
   " galloping of horses is deafening.");
  }
