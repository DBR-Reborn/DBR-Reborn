//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn4.c
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "West Of Intersection");
    set("long", "Where you stand the path is rather narrow, allowing "
    				 "room for two people walking abreast. The trees have "
                "creeped closer creating a feeling of being crowded in "
                "while also making the trail feel a bit more secure. "
                "East of here is a wooden building of some kind." );
    add_exit("newfirn2.c","west");
    add_exit("newfirn5.c","east");
    set_items(([
     ({ "path","road","trail" }) :
        "The walkway is quite narrow, roughly six or seven feet, and is "
        "made of firmly packed dirt. Footprints litter it making it look "
        "chaotic and sloppy.",
     ({ "trees","woods","forest" }) :
        "The woods is much more dense here than can be seen just to the "
        "east. Fewer plants grow on the forest floor due to the lack of "
        "sunlight and rain resulting in less spectacular view here.",
     ({ "building","house" }) :
     	  "It is not a small building and could be a shop based on the "
        "popular sizes for such establishments." ]));
    set_smell("default", "The air is refreshing. A piney smelly sap "
    							 "laces the air");
    set_listen("default", "You can hear nothing more than the creatures "
    							  "which inhabit the forest.");
}
