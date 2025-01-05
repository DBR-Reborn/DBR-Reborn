#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"
inherit ROOM;

void create() {
  ::create();
   set_property("light",2);
   set_property("night light",1);
   set_property("indoors", 1);
   set("short", "The dining room");
   set("day long", @DAY
You are in a fancy dining room, the large polished table covered
with expensive cloth and dishes.  Although Donny has been eating
alone recently, the room is fit for guests.  Delicious smells
fill the air, coming from the kitchen to the south.  A few small
clouds of smoke drift in from the east.
DAY
);
   set("night long", @NIGHT
This fancy dining room is faintly lit by candles set on a
large polished table.  Expensive cloth and dishes adorn the
table, leaving the room fit for royalty.  The kitchen is to the
south, the smell of food drifting in.  To the east is the living
room.
NIGHT
);
   add_item("table", "An expensive table made of wood, it is "+
   "well polished.");
   add_item("cloth", "Fancy cloth which adorns the table.");
   add_item("dishes", "Dishes and silverware are set out on the "+
   "table.  Very good quality stuff.");
   set_smell("default", "It smells of good food and smoke.");
   set_listen("default", "The clanging of dishes comes from the "+
   "south.");
   add_exit(TARAROOMS+"2rhs3", "east");
   add_exit(TARAROOMS+"2rhs2", "south");
}
