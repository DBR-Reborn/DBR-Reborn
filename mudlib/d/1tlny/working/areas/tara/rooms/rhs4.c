inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"


void create() {
  ::create();
   set_property("light", 2);
   set_property("night light", 1);
   set_property("indoors", 1);
   set("short","Living room");
   set("day long", @DAY
You are in the living room, comfortable sofa's are arranged around
the room.  A few small tables are around, their soul purpose to
provide space to set things.  Bright coloured rugs are layed out in
front of a large brick fireplace.  To the north is a kitchen, and east
the entryroom.
DAY
);
   set("night long", @NIGHT
This is the living room, in the luxurious halfling home.  A warm fire
in a fireplace keep the room well lit.  Sofa's are placed thoughout
the room, with a few small tables next to them.  Colorful rugs lay 
before a fireplace, there brilliant colors mixing with the flames
shadow.  There is a kitchen to the north, and entryroom to the east.
NIGHT
);
   add_exit(TARAROOMS+"rhs3", "north");
   add_exit(TARAROOMS+"rhs1", "east");
   add_item("sofa's", "Comfortable sitting couches lie thoughout the room");
   add_item("sofa", "Comfortable sitting couches lie thoughout the room");
   add_item("tables","Tables used to set things upon, tabacco "+
   "pipes, snacks, and other small items usually find there homes here");
   add_item("fireplace","A large fireplace, the chimney lets the "+
   "smoke out above ground.");
   add_item("rugs", "Colorful rugs with all sorts of designs adorn "+
   "the floor.");
   set_smell("default","The rooms smells of smoke from the fireplace.");
   set_listen("default","The sounds of conversations fill the air.");
}
