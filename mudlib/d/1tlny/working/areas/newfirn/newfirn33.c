//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn33.c
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "New Firn'Ville Room 33");
    set("long", "New Firn'Ville Room 33" );
    add_exit("inn.c", "north");
    add_exit("newfirn32.c", "west");
    add_exit("newfirn34.c", "east");
    set_items(([
     ({ "dirt" }) :
        "This is dirt.",
     ({ "tower" }) :
        "This is a tower." ]));
    set_smell("default", "The air smells like shit.");
    set_listen("default", "You hear someone taking a dump.");
}
