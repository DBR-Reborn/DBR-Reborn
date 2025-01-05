
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
    " The grass is about a foot shorter here then the rest of the plateau."
    );
    set_exits( ({  "plat38.c", "plat34.c", "plat32.c", "plat24.c" }),
      ({"north", "east", "west", "south" })
    );
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "The"  
   " galloping of horses is deafening.");
  }

void reset()   {
      ::reset(); 
	new(PLATMON + "ctft")->move(this_object());
      new(PLATMON + "ctmage")->move(this_object());
}
