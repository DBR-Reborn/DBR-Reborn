
#include <std.h>
#include </wizards/garetjax/plateau/defs.h>

inherit PLATROOMS + "falls";

void create() {
    ::create();
    set_property("light", 2);
    set_property("outdoors", 1);
    set("short", "The top of the ladder to Savanah");
   set_long( "\nAs you reach the top of the long climb, you stop at the"
   " edge and look at the top and the underside of the floating island. "
   "There is grass on the top, and you can see the roots sticking out"
   " from "
   "the bottom. Once on top, you notice that the island stretches for a"
   " long way."
    );
    set_exits( ({ "ladder.c", "plat4.c" }),
      ({ "down", "plateau" })
    );
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "The"  
    " galloping of horses is much closer now.");
  }
