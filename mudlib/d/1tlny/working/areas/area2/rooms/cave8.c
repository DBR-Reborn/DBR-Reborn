// cave 8

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("caveguard1","west");
    add_exit("caveguard2","east");
    add_exit("cave4","north");
    add_exit("cave10","south");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
}
