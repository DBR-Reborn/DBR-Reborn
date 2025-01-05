inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

void init() {
   ::init();
   add_action("read_sign","read");
}

void create() {
  ::create();
   set_property("light",2);
   set_property("night light",1);
   set("short", "Town of Tara");
   set("day long", @DAY
The entrance to the Township of Tara, not many buildings can be
seen outside, most are built into the hillside.  Halflings come
and go, eager to get there daily chores done, so they can
visit the tavern.  A grassy hillside spreads out before you,
many well-tended gardens can be seen outside underground homes.
DAY
);
   set("night long", @NIGHT
The entrance to the Township of Tara, it appears to be just
a hillside with a few buildings, in the darkness.  A few
torches are lit thoughout the town, making movement possible.
There is not much activity at this hour, as most of the
Halflings are asleep.
NIGHT
);
   add_item("sign","Try reading it.");
   add_item("buildings","Most of the buildings are built into "+
   "the hillside.  Only a few non-residence are out in the "+
   "open.");
   add_item("torches","Thoughtful citizens sometimes places "+
   "torches outside their houses.");
   add_item("town","The town spreads before you to the north.");
   add_item("hillside","The whole town is built upon this hillside.");
   set_listen("default", "You hear the sounds of a bustling town.");
   set_smell("default", "You can smell the fresh earth.");
   add_exit(TARAROOMS+"rm1", "north");
   new(TARAOBJ+"sign")->move(this_object());
}
int read_sign(string str){
  if(str != "sign") return 0;
  write("The sign reads: Welcome to Tara, may your stay be pleasant. "+
    "No violence is tolerated!\n");
  return 1;
}
