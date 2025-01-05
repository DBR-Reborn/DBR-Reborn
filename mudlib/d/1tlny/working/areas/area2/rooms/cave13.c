// cave 13

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("cave12","north");
    add_exit("cave14","southeast");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
}
