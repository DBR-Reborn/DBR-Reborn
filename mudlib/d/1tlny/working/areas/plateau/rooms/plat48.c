
#include <std.h>
#include </wizards/garetjax/plateau/defs.h>

inherit PLATROOMS + "jumpoff.c";

void create() {
    ::create();
    set_property("light", 2);
    set_property("outdoors", 1);
    set("short", "The Savanah Plateau");
   set_long( "\nYou are on a grassy plateau which stretches out to "
  "the south of you, and ends abruptly to the north of you in a deadly drop."
   " The jump down looks quite enticing, if you are in a hurry."
    );
    set_exits( ({  "plat37.c", "plat49.c", "plat47.c" }),
      ({"south",  "east", "west" })
    );
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "The"  
   " galloping of horses is deafening.");
  }

   void reset()   {
      ::reset(); 
      new(PLATMON + "ctmage")->move(this_object());
}