// wall 1

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("outpost4","ladder");
    add_exit("wall3","south");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
}
