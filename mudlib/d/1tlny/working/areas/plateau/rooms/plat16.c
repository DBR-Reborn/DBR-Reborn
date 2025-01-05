
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
    " Out of the corner of your eye, you see a round disk, but when you turn "
    "look straight at it, it is gone."
    );
    set_exits( ({  "plat27.c", "plat17.c", "plat15.c", "plat13.c" }),
      ({"north", "east", "west", "south" })
    );
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "The"  
   " galloping of horses is deafening.");
  }

   void reset()   {
      ::reset(); 
      new(PLATMON + "ctmage")->move(this_object());
}

