// outpost 5

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("outpost4","west");
    add_exit("outpost1","south");
    add_exit("outpost6","east");
    add_exit("outpost7","north");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
}
void reset() {
  object mon;
  ::reset();
    if(!present("ballista")) {
      new(A2OBJ+"ballista")->move(this_object());
  }
}
