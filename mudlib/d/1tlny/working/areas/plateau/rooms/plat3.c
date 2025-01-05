
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
   " The grass is curiously green here, instead of brown, like the rest of "
   "plateau's grass. "
    );
    set_exits( ({  "plat12.c", "plat4.c", "plat2.c" }),
      ({"north",  "east", "west" })
    );
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "The"  
   " galloping of horses is deafening.");
     add_item("grass", "After staring at the grass for a few minutes, you realize that the reason it is more green then the rest of the plateau, is that this is a centaur latrine!!");
  }

 void reset()   {
      ::reset(); 
	new(PLATMON + "ctft")->move(this_object());
      new(PLATMON + "ckid")->move(this_object());
}
