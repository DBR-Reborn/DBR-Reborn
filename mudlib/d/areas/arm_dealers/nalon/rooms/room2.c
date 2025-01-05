#include <dirs.h>
#include <std.h>
#include "../monk.h"
inherit "std/room";

void create() {
  ::create();
   set_property("light",2);
   add_exit(MONKROOMS+"room5", "southwest");
   add_exit(MONKROOMS+"room38", "west");
   add_exit(MONKROOMS+"room4", "south");
   add_exit(MONKROOMS+"room3", "north");
   add_exit(MONKROOMS+"room1", "east");
   set("short","Village path\n   0  \n   |  \n0--@--0\n  /|   \n 0 0  \n");
   set("long",
     "This path leads southwest, " +
     "deeper into the village.  " +
     "Huts lie to the north, south, and west.  " +
     "Small gardens are everywhere, " +
     "well tended by the caring monks. \n   0  \n   |  \n0--@--0\n  /|   \n 0 0  \n");
   add_item("huts","They are small but well contructed and stable.");
   add_item("garden","These are well tended by the monk gardeners.");
}

void reset() {
  ::reset();
   if(!present("monk")){
   new(MONKMOBS+"monk2.c")->move(this_object());
   new(MONKMOBS+"monk2.c")->move(this_object());
   new(MONKMOBS+"monk1.c")->move(this_object());
  }
}


