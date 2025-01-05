#include <dirs.h>
#include <std.h>
#include "../monk.h"
inherit ROOM;

void create() {
  ::create();
   set_property("light",2);
   add_exit(MONKROOMS+"room22", "south");
   add_exit(MONKROOMS+"room23", "west");
   add_exit(MONKROOMS+"room21", "north");
   add_exit(MONKROOMS+"room13", "east");
   set("short","Village path\n   0\n   | \n0--@--0\n   | \n   0\n");
   set("long",
"This is a village path leading west from the clearing.  To the "
"north is a large stone structure, probably the most "
"advanced building in the village.  To the south is a hut. "
"The path continues west to the outskirts of the village.\n   0\n   | \n0--@--0\n   | \n   0\n");
   add_item("hut","A medium sized hut, perhaps the home of a monk.");
   add_item("path","A path leading to the western outskirts of town.");
   add_item("building","The home of the villages wisest monk.");
   add_item("clearing","The center of the village.");
}
void reset() {
  ::reset();
   if(!present("monk")){
   new(MONKMOBS+"monk2.c")->move(this_object());
   new(MONKMOBS+"monk2.c")->move(this_object());
   new(MONKMOBS+"monk1.c")->move(this_object());
   }
}
