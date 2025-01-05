// cave 1

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("ravine11","north");
    add_exit("cave2","south");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
}
