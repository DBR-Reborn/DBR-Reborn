//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn10.c
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "East Intersection");
    set("long", "Two main trails meet here, one running only west "
    				 "from this point, the other going both north and "
                "south from here. You notice that the forest thins out "
                "considerably to the west while to the north and south "
                "it seems to be quite dense. The path here is hard packed "
                "and wide enough for four or five high-men walking abreast. "
                "In the distance to the west you can see the market, and "
                "to the north and south are a few buildings." );
    add_exit("newfirn11.c", "north");
    add_exit("newfirn9.c", "south");
    add_exit("newfirn36.c", "west");
    set_items(([
     ({ "dirt" }) :
        "This is dirt.",
     ({ "tower" }) :
        "This is a tower." ]));
    set_smell("default", "The air smells of nothing in particular.");
    set_listen("default", "You hear a gentle breeze.");
}
