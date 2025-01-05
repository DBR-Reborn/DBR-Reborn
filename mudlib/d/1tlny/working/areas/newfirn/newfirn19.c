//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn19.c
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "New Firn'Ville Room 19");
    set("long", "New Firn'Ville Room 19" );
    add_exit("newfirn39.c", "south");
    add_exit("newfirn20.c", "west");
    add_exit("newfirn18.c", "east");
    set_items(([
     ({ "dirt" }) :
        "This is dirt.",
     ({ "tower" }) :
        "This is a tower." ]));
    set_smell("default", "The air smells like shit.");
    set_listen("default", "You hear someone taking a dump.");
}
