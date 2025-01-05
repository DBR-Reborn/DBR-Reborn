//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn5.c
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("short", "South Of A Building");
    set("long", "There is something of a turnaround in the road here. "
    				 "A circular area has formed over the years allowing for "
                "traffic to wait on the side of the path to let others "
                "through. The forest hugs the trail closely providing "
                "a comfortable travelling area. Further east is a building "
                "much different than the one to the north." );
    add_exit("jesip_shop.c","north");
    add_exit("newfirn4.c","west");
    add_exit("newfirn6.c","east");
    set_items(([
     ({ "turnaround","trail","road","path", }) :
        "The loose dirt that makes the road here is quite dark and "
        "provides a slightly difficult travelling surface for large "
        "animals such as horses. A large circular turnaround type of "
        "area has formed just south of the path coming from the "
        "building, allowing easy manuver of luggage and animals through "
        "busy traffic.",
     ({ "woods","forest" }) :
        "The woods here is just as it is to the west: enourmously tall "
        "trees and little ground cover. A carpet of dead leaves is "
        "promenant down here below the forest canopy." ]));
    set_smell("default", "The air smells natural and fresh.");
    set_listen("default", "You don't hear much other than birds.");
}
