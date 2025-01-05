//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn12.c
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "New Firn'Ville Room 12");
    set("long", "New Firn'Ville Room 12" );
    add_exit("newfirn13.c", "north");
    add_exit("newfirn11.c", "south");
    add_exit("dwelling3.c", "west");
    add_exit("secret_exit_east.c", "east");
    add_invis_exit("east");
    set_items(([
     ({ "dirt" }) :
        "This is dirt.",
     ({ "tower" }) :
        "This is a tower." ]));
    set_smell("default", "The air smells like shit.");
    set_listen("default", "You hear someone taking a dump.");
}
