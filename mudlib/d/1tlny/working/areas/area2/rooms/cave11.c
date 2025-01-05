// cave 11

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("cave10","west");
    add_exit("cave12","east");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
}
