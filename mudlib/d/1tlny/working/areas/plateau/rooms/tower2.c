
#include <std.h>
#include "/wizards/garetjax/plateau/defs.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "A Short Guard Tower");
   set_long(
     "This guard tower stands on four legs about ten feet off the ground, "
     "and it feels like it could collapse at any moment. The floor is "
     "covered with horse hair, and the walls are very dirty."
    );
     add_exit("plat13", "out");
    set_smell("default", "The smell of horse hair is unmistakable.");
   set_listen("default", "The wind makes a whistling noise as it blows through the tower.");
  }

   void reset()   {
       ::reset();
      new(PLATMON + "ctgt") -> move(this_object());
}


