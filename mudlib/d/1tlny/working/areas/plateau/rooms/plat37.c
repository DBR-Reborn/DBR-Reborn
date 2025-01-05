
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
   " The surrounding air has taken on a darke and dismal quality to it, which seems to be emenating from the short guard tower in front of you."
    );
    set_exits( ({  "plat48.c", "tower3.c", "plat36.c", "plat38.c", "plat34.c" }),
      ({"north", "tower", "east", "west", "south" })
    );
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "The"  
   " galloping of horses is deafening.");
    add_item("tower", "A short guard tower with a ramp going up one end, you do not see how this makes it easier to guard since it is only about 5 feet high.");
  }
