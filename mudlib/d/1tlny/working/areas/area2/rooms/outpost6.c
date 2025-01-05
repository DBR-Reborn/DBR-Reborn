// outpost 6

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("outpost5","west");
    add_exit("outpost3","south");
    add_exit("wall2","ladder");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
}
