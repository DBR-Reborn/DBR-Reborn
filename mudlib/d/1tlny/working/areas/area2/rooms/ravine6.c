// ravine 6

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("outpost1","north");
    add_exit("ravine5","south");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
}
