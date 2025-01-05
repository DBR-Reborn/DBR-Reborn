//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn20.c
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "New Firn'Ville Room 20");
    set("long", "New Firn'Ville Room 20" );
    add_exit("secret_exit_north.c", "north");
    add_exit("magic_shop.c", "south");
    add_exit("newfirn21.c", "west");
    add_exit("newfirn19.c", "east");
    add_invis_exit("north");
    set_items(([
     ({ "dirt" }) :
        "This is dirt.",
     ({ "tower" }) :
        "This is a tower." ]));
    set_smell("default", "The air smells like shit.");
    set_listen("default", "You hear someone taking a dump.");
}
