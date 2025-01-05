
#include <std.h>
#include "/wizards/garetjax/plateau/defs.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "An Ominous Tower");
   set_long(
     "You are floating in a void."
    );
     add_exit("upstairs1", "down");
     add_invis_exit("down");
      set_listen("default","An Unidentifiable Humming.");
  }


