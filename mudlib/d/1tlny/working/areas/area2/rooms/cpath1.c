// cpath 1

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("trail","north");
    add_exit("cpath2","east");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
}
