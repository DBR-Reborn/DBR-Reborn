
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
   " The ground here is mushy and makes you uneasy."
    );
    set_exits( ({  "plat17.c", "plat11.c", "plat13.c", "plat3.c" }),
      ({"north", "east", "west", "south" })
    );
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "The"  
   " galloping of horses is deafening.");
    add_item("ground", "After staring at the ground here for a moment, your realize that the centaurs are fond of releaving themselves at this particular location.");
  }
 
void reset()   {
      ::reset(); 
	new(PLATMON + "ctft")->move(this_object());
      new(PLATMON + "ckid")->move(this_object());
	new(PLATMON + "ctmom")->move(this_object());
}
