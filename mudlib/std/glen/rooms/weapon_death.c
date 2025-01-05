
//      from the Nightmare mudlib
//      an example workroom for new immortals

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "be good room");
    set("night long", "be good room");
    set_property("no attack", 1);
    set_property("no steal", 1);
    set_property("no castle", 1);
    set_property("no spell", 1);
    set_property("no scry", 1);
    set_property("no summon", 1);
    set_property("no tansport", 1);
    set_property("no drain", 1);
    set_property("indoors", 1);
    set("day long", "It is day outside.\nA new immortal works here.\n");
    set_smell("default", "It smells like a new immortal in here.");
    set_listen("default", "You hear the sounds of code creation.");
}

