inherit "std/vault";
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"


void create() {
  ::create();
   set_property("light",2);
   set_property("night light",2);
   set_property("indoors", 1);
   set_door("wooden door", TARAROOMS+"rm9", "east", 0);
     set_open("wooden door", 0);
     set_locked("wooden door", 0);
   set("short","An entry room");
   set("day long", @DAY
This is the entry room for a wealthy halflings home.  The
room is colorful and lively, bright pictures hang on the wall,
and a coat rack rests near the wooden door.  Round windows look
out into a garden, and into town, giving a nice view.  A staircase
leads deeper into the hillside, and there are a rooms to the north
and west.
DAY
);
   set("night long", @NIGHT
You are in the entry room of a rich halflings house.  The room
is well lit by torches, allowing you to see colorful pictures which
hang on the wall.  A coat rack rests next to the wooden door, a few
round windows are near those.  A staircase leads down further into
the hill, displaying how deep this high budget house might have been
burrowed into the hillside.  There are rooms to the north and west.
NIGHT
);
   add_item("wooden door", "A well crafted wooden door, the inside "+
   "part is painted bright green.");
   add_item("pictures", "Paintings made as colorful as possible, "+
   "to liven up the place.");
   add_item("windows", "Round windows which look out into the town");
   add_item("garden", "A beautiful garden can be seen though the "+
   "windows");
   add_item("staircase", "The staircase leads further into the hillside.");
   add_item("torches", "Torches lit to keep the house nice and bright");
   add_item("rack", "A rack for hanging coats, right now it has "+
   "some brightly colored coats hanging on it.");
   set_smell("default", "The smell of cooking wafts in from the "+
   "north somewhere");
   set_listen("default", "Conversations can be heard.");
   add_exit(TARAROOMS+"rm9", "east");
   add_exit(TARAROOMS+"rhs4", "west");
   add_exit(TARAROOMS+"rhs2", "north");
   add_exit(TARAROOMS+"rhs5", "down");
}
