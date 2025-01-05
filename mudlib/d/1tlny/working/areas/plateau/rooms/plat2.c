
#include <std.h>
#include </wizards/garetjax/plateau/defs.h>

inherit PLATROOMS + "jumpoff.c";

void create() {
    ::create();
    set_property("light", 2);
    set_property("outdoors", 1);
    set("short", "The Savanah Plateau");
   set_long( "\nYou are on a grassy plateau which stretches out in "
  "front of you, and ends abruptly behind you in a deadly drop."
   " The jump down looks quite enticing, if you are in a hurry."
   " The grass rustles here, but you feel no wind. "
    );
    set_exits( ({  "plat13.c", "plat3.c", "plat1.c" }),
      ({"north",  "east", "west" })
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
