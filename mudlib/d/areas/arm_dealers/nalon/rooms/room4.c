#include <dirs.h>
#include <std.h>
#include "../monk.h"
inherit ROOM;

void create() {
  ::create();
   set_property("light",2);
   set_property("indoors",1);
   add_exit(MONKROOMS+"room2", "north");
   set("short","A small hut\n   0\n   | \n   @   \n     \n    \n");
   set("long",
"You are in the living quarters of a monk.  This hut is small and "
"cramped.  Although it seems sturdy and well built, it has "
"no windows or anything extraordinary.  A small bed lies up "
"against the wall, and a plain wooden table in the middle of "
"the room.\n   0\n   | \n   @   \n     \n    \n");
   add_item("table","An plain wooden table, has nothing on it.");
   add_item("bed","A small bed with no sheets.");
}

void reset() {
  ::reset();
{
   if(!present("monk"))
   new(MONKMOBS+"monk2.c")->move(this_object());
}
{
   if(!present("woman"))
   new(MONKMOBS+"monk_woman.c")->move(this_object());
}
}
