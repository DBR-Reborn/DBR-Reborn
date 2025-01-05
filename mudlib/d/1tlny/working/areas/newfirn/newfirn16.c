//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn16.c
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "New Firn'Ville Room 16");
    set("long", "New Firn'Ville Room 16" );
    add_exit("weapons.c", "south");
    add_exit("newfirn17.c", "west");
    add_exit("newfirn15.c", "east");
    set_items(([
     ({ "dirt" }) :
        "This is dirt.",
     ({ "tower" }) :
        "This is a tower." ]));
    set_smell("default", "The air smells like shit.");
    set_listen("default", "You hear someone taking a dump.");
}
