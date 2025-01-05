 
#include <std.h>
#include </wizards/garetjax/plateau/defs.h>

inherit PLATROOMS + "jumpoff.c";

void create() {
    ::create();
    set_property("light", 2);
    set_property("outdoors", 1);
    set("short", "The Savanah Plateau");
   set_long( "\nYou are on a grassy plateau which stretches out in "
   "front of you, and ends abruptly to the west of you in a deadly drop."
   " The jump down looks quite enticing, if you are in a hurry."
   " The ground is bare here, and there is a small hole in the ground."
    );
    set_exits( ({  "plat28.c", "plat16.c", "plat14.c" }),
      ({"north",  "east", "south" })
    );
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "The"  
   " galloping of horses is deafening.");
  }

 void reset()   {
      ::reset(); 
	new(PLATMON + "ckid")->move(this_object());
      new(PLATMON + "ctmom")->move(this_object());
}
