// farm 6

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("farm4","west");
    add_exit("farm7","north");
    add_exit("farm8","east");
    add_exit("barn","south");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
}
