//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn48.c
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "South West Side Of The Market");
    set("long", "Put Long Desc. Here!" );
    add_exit("newfirn47.c", "north");
    add_exit("newfirn49.c", "south");
    set_items(([
     ({ "dirt" }) :
        "This is dirt.",
     ({ "tower" }) :
        "This is a tower." ]));
    set_smell("default", "The air smells like shit.");
    set_listen("default", "You hear someone taking a dump.");
}
