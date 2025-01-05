//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn45.c
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "New Firn'Ville Room 45");
    set("long", "New Firn'Ville Room 45" );
    add_exit("newfirn42.c", "north");
    add_exit("newfirn48.c", "south");
    add_exit("newfirn41.c", "west");
    add_exit("newfirn46.c", "east");
    set_items(([
     ({ "dirt" }) :
        "This is dirt.",
     ({ "tower" }) :
        "This is a tower." ]));
    set_smell("default", "The air smells like shit.");
    set_listen("default", "You hear someone taking a dump.");
}
