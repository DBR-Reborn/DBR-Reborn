//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn27.c
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "New Firn'Ville Room 27");
    set("long", "New Firn'Ville Room 27" );
    add_exit("newfirn26.c", "north");
    add_exit("newfirn28.c", "south");
    add_exit("secret_exit_west.c", "west");
    add_invis_exit("west");
    set_items(([
     ({ "dirt" }) :
        "This is dirt.",
     ({ "tower" }) :
        "This is a tower." ]));
    set_smell("default", "The air smells like shit.");
    set_listen("default", "You hear someone taking a dump.");
}
