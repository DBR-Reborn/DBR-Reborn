// cave 6

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("cave9","south");
    add_exit("cavefount","north");
    add_exit("cave5","west");
    add_exit("cave7","east");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
}
