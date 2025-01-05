// king room

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("cave14","west");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
}
void reset() {
  object mon;
  ::reset();
    if(!present("throne")) {
      new(A2OBJ+"throne")->move(this_object());
  }
}
