
#include <std.h>
#include </wizards/garetjax/plateau/defs.h>

inherit PLATROOMS + "falls";

void create() {
    ::create();
    set_property("light", 2);
    set_property("outdoors", 1);
    set("short", "The ladder to Savanah");
   set_long( "\nYou stop in the middle of the ladder to survey your "
   "surroundings. Above you is the underside of the floating island, "
   "and far below you is the earth, spread out in all directions."
    );
    set_exits( ({ "entrance.c", "top.c" }),
      ({ "down", "up" })
    );
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "Off in the distance, you can hear the "  
    "galloping of horses.");
  }
