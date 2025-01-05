//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn17.c
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "New Firn'Ville Room 17");
    set("long", "New Firn'Ville Room 17" );
    add_exit("newfirn18.c", "west");
    add_exit("newfirn16.c", "east");
    set_items(([
     ({ "dirt" }) :
        "This is dirt.",
     ({ "tower" }) :
        "This is a tower." ]));
    set_smell("default", "The air smells like shit.");
    set_listen("default", "You hear someone taking a dump.");
}
