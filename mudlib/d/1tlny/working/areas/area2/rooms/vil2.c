// vil 2

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("vil3","west");
    add_exit("vil4","southeast");
    add_exit("vil5","north");
    add_exit("vil1","southwest");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
}
