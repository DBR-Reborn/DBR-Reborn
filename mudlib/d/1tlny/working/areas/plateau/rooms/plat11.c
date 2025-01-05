
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
   " There are fresh hoof marks concentrated in this area, around a burnt out "
   "campfire."
    );
    set_exits( ({  "plat18.c", "plat10.c", "plat12.c", "plat4.c" }),
      ({"north", "east", "west", "south" })
    );
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "The"  
   " galloping of horses is deafening.");
  }

   void reset()   {
      ::reset(); 
	new(PLATMON + "ctft")->move(this_object());
      new(PLATMON + "ctft")->move(this_object());
}