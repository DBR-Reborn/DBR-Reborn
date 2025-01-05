//    Mine shop.
//    -Diewarzau 1/29/96
//    DarkeLIB 1.0
#define MINE_D "/daemon/mine_d"
#define MAX_SOUTH 79
#define MAX_EAST 39
#include <rooms.h>
#include <security.h>
#include "../shards.h"

inherit "/std/room";

void reset() {
  ::reset();
  if(!present("sphere"))
    new(OBJ+"mine_crystal")->move(this_object());
  return;
}

void create() {
  ::create();
  add_exit(ROOMS+"ak_tavern3", "west");
  set_short("The Mine Shop");
  set_long(
  "This small shack is pretty much completely empty. The only thing of note is some odd tools lying around, and a sign in a corner of the room.");
  set_items(([ ({ "tools", "mining tools" }) : "They are various picks, hammers, etc. They're rusted beyond use, though.",
      "sign" : (: call_other, this_object(), "read_sign" :) ]) );
  set_property("light", 1);
  set_property("indoors", 1);
  return;
}

int read_sign() {
  string tmp;

  tmp =
"Welcome to the Mine Shop.\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
"Here, you may buy a mine on the world map as well as hire \n"
"mine workers.  As time passes, depending on where the mine is\n"
"built, certain minerals will be stocked in the mineral chest, and\n"
"may be removed by you.  If you fail to pay your staff for the\n"
"coming month before the current month is up, your mine WILL BE\n"
"LOST.  You may only own one mine at a time.\n"
"\n"
"Item     Description                         Cost\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
"The rest of the sign is covered in blood.\n";

  this_player()->more(explode(tmp, "\n"));
  return 1;
}
