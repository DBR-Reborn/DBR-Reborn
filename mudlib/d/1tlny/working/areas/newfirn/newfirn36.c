//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn36.c
#include <std.h>
inherit VAULT;
void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("short", "South Of A Building");
    set("long", "You stand just south of a large building. The road here "
    			    "is covered with metal bits and shavings. To the east is "
                "an intersection and west is where the market takes place. "
                "The forest here is rather young, the trees are thin and "
                "of mediocre height. Sparse foliage covers the forest "
                "floor." );
    add_exit("schtel_shop.c", "north");
    add_exit("newfirn35.c", "west");
	 add_exit("newfirn10.c", "east");
    set_items(([
     ({ "building" }) :
        "It's a wood cabin and is built with all sides of equal length. "
        "There is a large open area in the center of the roof from which "
        "billows hot air and some smoke.",
     ({ "metal","bits","shavings" }) :
        "The road here is covered with little pieces of metal, more than "
        "likely from some sort of metal shaping or forging. You can "
        "see that there is more of it to the north between you and the "
        "building." ]));
    set_smell("default", "The air here smells of hot metal.");
    set_listen("default", "You can hear rhythmic pounding of metal on "
    							  "metal.");
}
