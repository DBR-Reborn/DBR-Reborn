
#include <std.h>
#include "/wizards/garetjax/plateau/defs.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "A Hermit's Hut");
   set_long(
    "You are on a bare patch of ground, surrounded by mist so thick, you cant"
    " see the edge of your eyeball."
    );
     add_exit("plat28", "out");
     set_smell("default", "The air is odorless.");
     set_listen("default", "There is no sound here.");
  }

   void reset()   {
       ::reset();
      new(PLATMON + "specguard") -> move(this_object());
}


