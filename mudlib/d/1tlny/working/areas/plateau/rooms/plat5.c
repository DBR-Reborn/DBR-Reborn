
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
   " There is an imprint of a centaur's body, pressed into the grass."
    );
    set_exits( ({  "plat10.c", "plat6.c", "plat4.c" }),
      ({"north",  "east", "west" })
    );
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "The"  
   " galloping of horses is deafening.");
    add_item("imprint", "It appears that the body of a centaur laid here for quiet sometime, before it was dragged to the edge and thrown off.");
  }

 void reset()   {
      ::reset(); 
	new(PLATMON + "ctft")->move(this_object());
      new(PLATMON + "ckid")->move(this_object());
}
