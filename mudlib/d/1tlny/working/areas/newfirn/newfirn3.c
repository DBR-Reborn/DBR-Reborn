//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn3.c
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "South Of Market Square");
    set("long", "The road widens here as a result of heavy traffic and "
    				 "overflow from the market to the north. On busy days "
                "merchants will sit here peddling goods and valuables "
                "to citizens of New Firn'Ville and travellers alike. "
                "Huge trees surround the road, bordered by a thick edge "
                "of small foliage. To the west is a small cabin and to "
                "the east is a small empty clearing." );
    add_exit("newfirn49.c","north");
    add_exit("newfirn2.c","south");
    add_exit("dwelling2.c","west");
    add_exit("tunnels1.c","east");
    set_items(([
     ({ "road","path","trail" }) :
        "The road is dirt, compressed to a hard surface over the years "
        "of heavy usage. Some rocks and stones have become lodged into "
        "the dirt and provide structure to it. In some places the manure "
        "of animals such as horses and goats litters the path.",
     ({ "trees","foliage","plants" }) :
        "Both the foliage and trees are very impressive. The trees have "
        "been here for hundreds of years as shown by their immense size, "
        "while the foliage is brilliantly green and plush to the point "
        "that it looks like a nice place to rest for a while.",
     ({ "cabin","house" }) :
        "The cabin is smallish, although not tiny. It is constructed of "
        "strong logs and covered by a ceder planked roof. Overall it looks "
        "like a wonderful place to live.",
     ({ "clearing" }) :
        "It is a clearing in the trees and is filled with tall grasses "
        "which blow about in the wind like waves on a sea." ]));
    set_smell("default", "While fresh like a healthy forest, the air has "
    							 "picked up numerous scents from the market and "
                         "shops to the north.");
    set_listen("default", "You barely make out the sounds of birds and "
    							  "insects chirping over the sound of the market.");
}
