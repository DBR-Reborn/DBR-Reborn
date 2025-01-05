// cave fount

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("cave6","south");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
    new("/wizards/leander/area2/obj/troth")->move(this_object()); 
}
