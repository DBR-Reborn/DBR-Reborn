// farm 1

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("vil4","west");
    add_exit("farm2","east");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
}
