
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
   " A cricket chirps once, then ominously falls silent."
    );
    set_exits( ({  "plat9.c", "plat7.c", "plat5.c" }),
      ({"north",  "east", "west" })
    );
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "The"  
   " galloping of horses is deafening.");
    add_item("cricket", "A tiny little thing, that amazingly makes more racket then seems possible for his smile size. He moves so fast, that no matter how hard you try, you cant squish him.");
  }

   void reset()   {
      ::reset(); 
	new(PLATMON + "ctft")->move(this_object());
      new(PLATMON + "ctft")->move(this_object());
}
