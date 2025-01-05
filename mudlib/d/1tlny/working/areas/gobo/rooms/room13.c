// Area:  Gobo cave
// Coders: Amel and Arctic
// May, 97
// Room: room13.c

#include <dirs.h>
#include <std.h>
#include <def.h>
#include "../gobo.h"

inherit ROOM;

void create()
{
  ::create();
  set_property("indoors", 1);
  set_property("light", 1);
  set_property("night light", 0);
  set("short", "A small underground passage");
  set("long",
"You trudge through the cave and find the walls closing in about you.  "
"The small cave has become a narrow passage and you find your "
"shoulders brushing the walls.");
  set_items(([({"wall","walls"}):
"The walls are solid stone rough to the touch and tears at your skin "
"and clothes."]));
set_exits((["east":GOBROOMS+"room12","north":GOBROOMS+"room14"]));
  set_smell("default",
"The smoke of burning wet wood hangs in the air.");
  set_listen("default",
"A soft chanting sound can be heard to the north.");
}

void reset()
{
  ::reset();
/*
  if(!present(gobo_male) && (random(10) < 1))
     new(GOBMONSTERS+"gobo_malea")->move(TO);
*/
}
