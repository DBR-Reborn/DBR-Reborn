inherit VAULT;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

void create() {
  ::create();
   set_property("light", 2);
   set_property("night light", 1);
   set_door("round door", TARAROOMS+"sp1", "west", 0);
    set_open("round door", 1);
    set_locked("round door", 0);
    set_open_function("open_door", "3:30:00");
    set_close_function("close_door", "17:30:00");
   set("short", "A lane of shops");
   set("day long", @DAY
You stand on a bustling street filled with shops and restaraunts.
Halfings come and go, getting there daily shopping and chores
done, or just coming to enjoy a fancy meal outside of there homes.
To the west is a general store, a seller and buyer of many
goods.  To the north the street continues alongside a few shops,
beyond that are the houses of the middle class.
DAY
);
   set("night long", @NIGHT
You stand on an empty lane, closed shops line the street,
filled with business during the day, but dark and empty at night.
To the southeast is a building that is not built into the hillside
like those around it.  It is also the only building that is open
at this time of night.
NIGHT
);
   add_item("shops", "Shops line the road, many halflings have "+
   "established their business here.");
   add_item("restaraunts", "A few restaraunts are along the street");
   add_item("store", "A general store to the west, the owner "+
   "buys and sells many goods.");
   add_item("building", "The only building that is built outside "+
   "of the hill lies to the southeast.");
   set_smell("default","It smells of well cooked foods");
   set_listen("default","It sounds like a busy marketplace.");
   add_exit(TARAROOMS+"rm17", "southeast");
   add_exit(TARAROOMS+"sp1", "west");
}

void close_door() {
   call_other(TARAROOMS+"sp1", "close_door");
   return;
}

void open_door() {
   call_other(TARAROOMS+"sp1", "open_door");
   return;
}
